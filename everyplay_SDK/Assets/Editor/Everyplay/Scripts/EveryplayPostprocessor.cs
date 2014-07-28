using System;
using System.IO;
using System.Xml;
using System.Reflection;
using System.Collections;
using System.Collections.Generic;

using UnityEngine;
using UnityEditor;
using UnityEditor.Callbacks;
using Everyplay.XCodeEditor;

public static class EveryplayPostprocessor
{
    [PostProcessBuild(1080)]
    public static void OnPostProcessBuild(BuildTarget target, string path)
    {
        EveryplaySettings settings = (EveryplaySettings)Resources.Load(EveryplaySettingsEditor.settingsFile);

        if(settings != null) {
            if(settings.IsEnabled) {
                if(settings.IsValid) {
                    if(target == BuildTarget.iPhone) {
                        PostProcessBuild_iOS(path, settings.clientId);
                    }
                    else if(target == BuildTarget.Android) {
                        PostProcessBuild_Android(path, settings.clientId);
                    }
                }
                else {
                    Debug.LogError("Everyplay will be disabled because client id, client secret or redirect URI was not valid.");
                    if(target == BuildTarget.iPhone) {
                        SetEveryplayEnabledForTarget(BuildTargetGroup.iPhone, false);
                    }
                    else if(target == BuildTarget.Android) {
                        SetEveryplayEnabledForTarget(BuildTargetGroup.Android, false);
                    }
                }
            }
        }
    }

    [PostProcessBuild(-10)]
    public static void OnPostProcessBuildEarly(BuildTarget target, string path)
    {
        EveryplayLegacyCleanup.Clean(false);

        if(target == BuildTarget.iPhone || target == BuildTarget.Android) {
            ValidateAndUpdateFacebook();

            if(target == BuildTarget.iPhone) {
                FixUnityPlistAppendBug(path);
            }
        }
    }

    [PostProcessScene]
    public static void OnPostprocessScene()
    {
        EveryplaySettings settings = (EveryplaySettings)Resources.Load(EveryplaySettingsEditor.settingsFile);

        if(settings != null) {
            if(settings.IsValid && settings.IsEnabled) {
                GameObject everyplayEarlyInitializer = new GameObject("EveryplayEarlyInitializer");
                everyplayEarlyInitializer.AddComponent<EveryplayEarlyInitializer>();
            }
        }
    }

    private static void PostProcessBuild_iOS(string path, string clientId)
    {
        CreateModFile(path);
        CreateEveryplayConfig(path);
        ProcessGlesFiles(path);
        ProcessXCodeProject(path);
        ProcessInfoPList(path, clientId);
        SetEveryplayEnabledForTarget(BuildTargetGroup.iPhone, true);
    }

    private static void PostProcessBuild_Android(string path, string clientId)
    {
        SetEveryplayEnabledForTarget(BuildTargetGroup.Android, true);
    }

	//生成EveryplayConfig.h文件，里面只有两行代码
    private static void CreateEveryplayConfig(string path)
    {
        try {
            string configFile = System.IO.Path.Combine(path, "Everyplay/EveryplayConfig.h");

            if(File.Exists(configFile)) {
                File.Delete(configFile);
            }

            string version = GetUnityVersion();

            using(StreamWriter streamWriter = File.CreateText(configFile)) {
                streamWriter.WriteLine("// Autogenerated by EveryplayPostprocess.cs");
                streamWriter.WriteLine("#define EVERYPLAY_UNITY_VERSION " + version);
            }
        }
        catch(Exception e) {
            Debug.Log("Creating EveryplayConfig.h failed: " + e);
        }
    }

    private static void ProcessGlesFiles(string path)
    {
        string helperFile = System.IO.Path.Combine(path, "Classes/Unity/GlesHelper.mm");
        string supportFile = System.IO.Path.Combine(path, "Classes/iPhone_GlesSupport.cpp");

        if(File.Exists(helperFile)) {
            UpdateStringInFile(helperFile, "\"#include \"EveryplayGlesSupport.h\"\n", "");
            UpdateStringInFile(helperFile, "\"GlesHelper.h\"", "\"GlesHelper.h\"\n#include \"EveryplayGlesSupport.h\"");
        }
        else if(File.Exists(supportFile)) {
            UpdateStringInFile(supportFile, "#include \"EveryplayGlesSupport.h\"", "");
            UpdateStringInFile(supportFile, "\"iPhone_GlesSupport.h\"", "\"iPhone_GlesSupport.h\"\n#include \"EveryplayGlesSupport.h\"");
        }
    }

    private static void ProcessXCodeProject(string path)
    {
        Everyplay.XCodeEditor.XCProject project = new Everyplay.XCodeEditor.XCProject(path);

        string modsPath = System.IO.Path.Combine(path, "Everyplay");
        string[] files = System.IO.Directory.GetFiles(modsPath, "*.projmods", System.IO.SearchOption.AllDirectories);

        foreach(string file in files) {
            project.ApplyMod(Application.dataPath, file);
        }

        project.Save();
    }

    private static void ProcessInfoPList(string path, string clientId)
    {
        try {
            string file = System.IO.Path.Combine(path, "Info.plist");

            if(!File.Exists(file)) {
                return;
            }

            XmlDocument xmlDocument = new XmlDocument();

            xmlDocument.Load(file);

            XmlNode dict = xmlDocument.SelectSingleNode("plist/dict");

            if(dict != null) {
                // Add Facebook application id if not defined

                PListItem facebookAppId = GetPlistItem(dict, "FacebookAppID");

                if(facebookAppId == null) {
                    XmlElement key = xmlDocument.CreateElement("key");
                    key.InnerText = "FacebookAppID";

                    XmlElement str = xmlDocument.CreateElement("string");
                    str.InnerText = FacebookAppId;

                    dict.AppendChild(key);
                    dict.AppendChild(str);
                }

                // Add url schemes

                PListItem bundleUrlTypes = GetPlistItem(dict, "CFBundleURLTypes");

                if(bundleUrlTypes == null) {
                    XmlElement key = xmlDocument.CreateElement("key");
                    key.InnerText = "CFBundleURLTypes";

                    XmlElement array = xmlDocument.CreateElement("array");

                    bundleUrlTypes = new PListItem(dict.AppendChild(key), dict.AppendChild(array));
                }

                AddUrlScheme(xmlDocument, bundleUrlTypes.itemValueNode, UrlSchemePrefixFB + clientId);
                AddUrlScheme(xmlDocument, bundleUrlTypes.itemValueNode, UrlSchemePrefixEP + clientId);

                xmlDocument.Save(file);

                // Remove extra gargabe added by the XmlDocument save
                UpdateStringInFile(file, "dtd\"[]>", "dtd\">");
            }
            else {
                Debug.Log("Info.plist is not valid");
            }
        }
        catch(Exception e) {
            Debug.Log("Unable to update Info.plist: " + e);
        }
    }

    private static void AddUrlScheme(XmlDocument xmlDocument, XmlNode dictContainer, string urlScheme)
    {
        if(!CheckIfUrlSchemeExists(dictContainer, urlScheme)) {
            XmlElement dict = xmlDocument.CreateElement("dict");

            XmlElement str = xmlDocument.CreateElement("string");
            str.InnerText = urlScheme;

            XmlElement key = xmlDocument.CreateElement("key");
            key.InnerText = "CFBundleURLSchemes";

            XmlElement array = xmlDocument.CreateElement("array");
            array.AppendChild(str);

            dict.AppendChild(key);
            dict.AppendChild(array);

            dictContainer.AppendChild(dict);
        }
        else {
            //Debug.Log("URL Scheme " + urlScheme + " already existed");
        }
    }

    private static bool CheckIfUrlSchemeExists(XmlNode dictContainer, string urlScheme)
    {
        foreach(XmlNode dict in dictContainer.ChildNodes) {
            if(dict.Name.ToLower().Equals("dict")) {
                PListItem bundleUrlSchemes = GetPlistItem(dict, "CFBundleURLSchemes");

                if(bundleUrlSchemes != null) {
                    if(bundleUrlSchemes.itemValueNode.Name.Equals("array")) {
                        foreach(XmlNode str in bundleUrlSchemes.itemValueNode.ChildNodes) {
                            if(str.Name.Equals("string")) {
                                if(str.InnerText.Equals(urlScheme)) {
                                    return true;
                                }
                            }
                            else {
                                Debug.Log("CFBundleURLSchemes array contains illegal elements.");
                            }
                        }
                    }
                    else {
                        Debug.Log("CFBundleURLSchemes contains illegal elements.");
                    }
                }
            }
            else {
                Debug.Log("CFBundleURLTypes contains illegal elements.");
            }
        }

        return false;
    }

    public class PListItem
    {
        public XmlNode itemKeyNode;
        public XmlNode itemValueNode;

        public PListItem(XmlNode keyNode, XmlNode valueNode)
        {
            itemKeyNode = keyNode;
            itemValueNode = valueNode;
        }
    }

    public static PListItem GetPlistItem(XmlNode dict, string name)
    {
        for(int i=0; i<dict.ChildNodes.Count-1; i++) {
            XmlNode node = dict.ChildNodes.Item(i);

            if(node.Name.ToLower().Equals("key") && node.InnerText.ToLower().Equals(name.Trim().ToLower())) {
                XmlNode valueNode = dict.ChildNodes.Item(i + 1);

                if(!valueNode.Name.ToLower().Equals("key")) {
                    return new PListItem(node, valueNode);
                }
                else {
                    Debug.Log("Value for key missing in Info.plist");
                }
            }
        }

        return null;
    }

    private static void UpdateStringInFile(string file, string subject, string replacement)
    {
        try {
            if(!File.Exists(file)) {
                return;
            }

            string processedContents = "";

            using(StreamReader sr = new StreamReader(file)) {
                while(sr.Peek() >= 0) {
                    string line = sr.ReadLine();
                    processedContents += line.Replace(subject, replacement) + "\n";
                }
            }

            File.Delete(file);

            using(StreamWriter streamWriter = File.CreateText(file)) {
                streamWriter.Write(processedContents);
            }
        }
        catch(Exception e) {
            Debug.Log("Unable to update string in file: " + e);
        }
    }

    public static string GetUnityVersion()
    {
        #if UNITY_3_5
        return"350";
        #elif (UNITY_4_0 || UNITY_4_0_1)
        return "400";
        #elif UNITY_4_1
        return "410";
        #elif UNITY_4_2
        return "420";
        #else
        return "0";
        #endif
    }

    private static void CreateModFile(string path)
    {
        Dictionary<string, object> mod = new Dictionary<string, object>();

        List<string> patches = new List<string>();
        List<string> libs = new List<string>();
        List<string> librarysearchpaths = new List<string>();

        List<string> frameworksearchpaths = new List<string>();
        frameworksearchpaths.Add("Plugins/Everyplay/iOS");

        List<string> frameworks = new List<string>();
        frameworks.Add("AdSupport.framework:weak");
        frameworks.Add("AssetsLibrary.framework");
        frameworks.Add("CoreImage.framework:weak");
        frameworks.Add("MessageUI.framework");
        frameworks.Add("Security.framework");
        frameworks.Add("Social.framework:weak");
        frameworks.Add("StoreKit.framework");
        frameworks.Add("Twitter.framework:weak");
        frameworks.Add("Accounts.framework:weak");

        List<string> files = new List<string>();
        files.Add("Plugins/Everyplay/iOS/Everyplay.framework");
        files.Add("Plugins/Everyplay/iOS/Everyplay.bundle");
        files.Add("Plugins/Everyplay/iOS/EveryplayGlesSupport.h");
        files.Add("Plugins/Everyplay/iOS/EveryplayGlesSupport.mm");
        files.Add("Plugins/Everyplay/iOS/EveryplayUnity.h");
        files.Add("Plugins/Everyplay/iOS/EveryplayUnity.mm");
        files.Add(System.IO.Path.Combine(path, "Everyplay/EveryplayConfig.h"));

        List<string> headerpaths = new List<string>();
        headerpaths.Add("Plugins/Everyplay/iOS");

        List<string> folders = new List<string>();
        List<string> excludes = new List<string>();

        mod.Add("group", "Everyplay");
        mod.Add("patches", patches);
        mod.Add("libs", libs);
        mod.Add("librarysearchpaths", librarysearchpaths);
        mod.Add("frameworksearchpaths", frameworksearchpaths);
        mod.Add("frameworks", frameworks);
        mod.Add("headerpaths", headerpaths);
        mod.Add("files", files);
        mod.Add("folders", folders);
        mod.Add("excludes", excludes);

        string jsonMod = EveryplayMiniJSON.Json.Serialize(mod);

        string modPath = System.IO.Path.Combine(path, "Everyplay");
        string file = System.IO.Path.Combine(modPath, "EveryplayXCode.projmods");

        if(!Directory.Exists(modPath)) {
            Directory.CreateDirectory(modPath);
        }
        if(File.Exists(file)) {
            File.Delete(file);
        }

        using(StreamWriter streamWriter = File.CreateText(file)) {
            streamWriter.Write(jsonMod);
        }
    }

    public static void SetEveryplayEnabledForTarget(BuildTargetGroup target, bool enabled)
    {
        string targetDefine = "";

        if(target == BuildTargetGroup.iPhone) {
            targetDefine = "EVERYPLAY_IPHONE";
        }
        else if(target == BuildTargetGroup.Android) {
            targetDefine = "EVERYPLAY_ANDROID";
        }

        #if UNITY_3_5
        SetGlobalCustomDefine("smcs.rsp", targetDefine, enabled);
        SetGlobalCustomDefine("gmcs.rsp", targetDefine, enabled);
        #else
        SetScriptingDefineSymbolForTarget(target, targetDefine, enabled);
        #endif
    }

    private static void SetScriptingDefineSymbolForTarget(BuildTargetGroup target, string targetDefine, bool enabled)
    {
        #if !UNITY_3_5
        string defines = PlayerSettings.GetScriptingDefineSymbolsForGroup(target);

        defines = defines.Replace(targetDefine, "");
        defines = defines.Replace(";;", ";");

        if(enabled) {
            if(defines.Length > 0) {
                defines = targetDefine + ";" + defines;
            }
            else {
                defines = targetDefine;
            }
        }

        PlayerSettings.SetScriptingDefineSymbolsForGroup(target, defines);
        #endif
    }

    private static void SetGlobalCustomDefine(string file, string targetDefine, bool enabled)
    {
        string fileWithPath = System.IO.Path.Combine(Application.dataPath, file);

        if(File.Exists(fileWithPath)) {
            UpdateStringInFile(fileWithPath, targetDefine, "");
            UpdateStringInFile(fileWithPath, ";;", ";");
            UpdateStringInFile(fileWithPath, ":;", ":");

            string processedContents = "";
            bool foundDefine = false;

            using(StreamReader sr = new StreamReader(fileWithPath)) {
                while(sr.Peek() >= 0) {
                    string line = sr.ReadLine();
                    if(line.Contains("-define:") && !foundDefine) {
                        if(enabled) {
                            processedContents += line.Replace("-define:", "-define:" + targetDefine + ";") + "\n";
                        }
                        else {
                            if(!(line.ToLower().Trim().Equals("-define:"))) {
                                processedContents += line + "\n";
                            }
                        }
                        foundDefine = true;
                    }
                    else {
                        processedContents += line + "\n";
                    }
                }
            }

            if(!foundDefine) {
                processedContents += "-define:" + targetDefine;
            }

            File.Delete(fileWithPath);

            if(processedContents.Length > 0) {
                using(StreamWriter streamWriter = File.CreateText(fileWithPath)) {
                    streamWriter.Write(processedContents);
                }
            }
            else {
                string metaFile = fileWithPath + ".meta";

                if(File.Exists(metaFile)) {
                    File.Delete(metaFile);
                }
            }
        }
        else if(enabled) {
            using(StreamWriter streamWriter = File.CreateText(fileWithPath)) {
                streamWriter.Write("-define:" + targetDefine);
            }
        }
    }

    public static void ValidateAndUpdateFacebook()
    {
        try {
            Type facebookSettingsType = Type.GetType("FBSettings,Assembly-CSharp", false, true);

            if(facebookSettingsType != null) {
                MethodInfo[] methodInfos = facebookSettingsType.GetMethods(BindingFlags.Public | BindingFlags.Static | BindingFlags.Instance | BindingFlags.NonPublic);

                MethodInfo getInstance = null;
                MethodInfo getAppIds = null;
                MethodInfo setAppIds = null;
                MethodInfo setAppLabels = null;
                MethodInfo getAppLabels = null;

                foreach(MethodInfo methodInfo in methodInfos) {
                    if(methodInfo.Name.Equals("get_Instance")) {
                        getInstance = methodInfo;
                    }
                    else if(methodInfo.Name.Equals("get_AppIds")) {
                        getAppIds = methodInfo;
                    }
                    else if(methodInfo.Name.Equals("set_AppIds")) {
                        setAppIds = methodInfo;
                    }
                    else if(methodInfo.Name.Equals("get_AppLabels")) {
                        getAppLabels = methodInfo;
                    }
                    else if(methodInfo.Name.Equals("set_AppLabels")) {
                        setAppLabels = methodInfo;
                    }
                }

                if(getAppIds != null && getAppLabels != null && setAppIds != null && setAppLabels != null && getInstance != null) {
                    object facebookSettings = getInstance.Invoke(null, null);

                    if(facebookSettings != null) {
                        string[] currentAppIds = (string[])getAppIds.Invoke(facebookSettings, null);
                        string[] currentAppLabels = (string[])getAppLabels.Invoke(facebookSettings, null);

                        if(currentAppIds != null && currentAppLabels != null) {
                            bool addEveryplay = true;
                            bool updated = false;

                            List<string> appLabelList = new List<string>();
                            List<string> appIdList = new List<string>();

                            for(int i=0; i<Mathf.Min(currentAppIds.Length, currentAppLabels.Length); i++) {
                                // Skip invalid items
                                bool shouldSkipItem = (currentAppIds[i] == null || currentAppIds[i].Trim().Length < 1 || currentAppIds[i].Trim().Equals("0") || currentAppLabels[i] == null);

                                // Check if we already have an Everyplay item or it is malformed or a duplicate
                                if(!shouldSkipItem) {
                                    if(currentAppLabels[i].Equals("Everyplay") && currentAppIds[i].Equals(FacebookAppId)) {
                                        if(addEveryplay) {
                                            addEveryplay = false;
                                        }
                                        else {
                                            shouldSkipItem = true;
                                        }
                                    }
                                    else if(currentAppIds[i].Trim().ToLower().Equals(FacebookAppId)) {
                                        shouldSkipItem = true;
                                    }
                                }

                                if(!shouldSkipItem) {
                                    appIdList.Add(currentAppIds[i]);
                                    appLabelList.Add(currentAppLabels[i]);
                                }
                                else {
                                    updated = true;
                                }
                            }

                            if(addEveryplay) {
                                appLabelList.Add("Everyplay");
                                appIdList.Add(FacebookAppId);
                                updated = true;
                            }

                            if(updated) {
                                object[] setAppLabelsObjs = { appLabelList.ToArray() };
                                setAppLabels.Invoke(facebookSettings, setAppLabelsObjs);
                                object[] setAppIdsObjs = { appIdList.ToArray() };
                                setAppIds.Invoke(facebookSettings, setAppIdsObjs);
                            }
                        }
                    }
                }
            }
            else {
                Debug.Log("To use the Facebook native login with Everyplay, please import Facebook SDK for Unity.");
            }
        }
        catch(Exception e) {
            Debug.Log("Unable to validate and update Facebook: " + e);
        }
    }

    // This fixes an Info.plist append bug near UIInterfaceOrientation on some Unity versions (atleast on Unity 4.2.2)
    private static void FixUnityPlistAppendBug(string path)
    {
        try {
            string file = System.IO.Path.Combine(path, "Info.plist");

            if(!File.Exists(file)) {
                return;
            }

            string processedContents = "";
            bool bugFound = false;

            using(StreamReader sr = new StreamReader(file)) {
                bool previousWasEndString = false;
                while(sr.Peek() >= 0) {
                    string line = sr.ReadLine();

                    if(previousWasEndString && line.Trim().StartsWith("</string>")) {
                        bugFound = true;
                    }
                    else {
                        processedContents += line + "\n";
                    }

                    previousWasEndString = line.Trim().EndsWith("</string>");
                }
            }

            if(bugFound) {
                File.Delete(file);

                using(StreamWriter streamWriter = File.CreateText(file)) {
                    streamWriter.Write(processedContents);
                }

                Debug.Log("EveryplayPostprocessor found and fixed a known Unity plist append bug in the Info.plist.");
            }
        }
        catch(Exception e) {
            Debug.Log("Unable to process plist file: " + e);
        }
    }

    private const string FacebookAppId = "182473845211109";
    private const string UrlSchemePrefixFB = "fb182473845211109ep";
    private const string UrlSchemePrefixEP = "ep";
}
