using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor.Callbacks;
using UnityEditor;
using sharePlus.XCodeEditor;
using System.Xml;
using System;
using System.IO;
using System.Reflection;

public class sharePlusPostprocessor {

	[PostProcessBuild(1080)]
	public static void OnPostProcessBuild(BuildTarget target, string path)
	{
		sharePlusSettings settings = (sharePlusSettings)Resources.Load (sharePlusSettingEditor.settingsFile);

		if (settings != null) {
			if(settings.IsEnabled) {
				if(settings.IsValid) {
					if(target == BuildTarget.iPhone) {
						PostProcessBuild_iOS(path, settings.key);
					}
					else if(target == BuildTarget.Android) {
						//PostProcessBuild_Android(path, settings.clientId);
					}
				}
				else {
					Debug.LogError("sharePlus will be disabled because client id, client secret or redirect URI was not valid.");
					if(target == BuildTarget.iPhone) {
						SetsharePlusEnabledForTarget(BuildTargetGroup.iPhone, false);
					}
					else if(target == BuildTarget.Android) {
						SetsharePlusEnabledForTarget(BuildTargetGroup.Android, false);
					}
				}
			}
		}
	}

	[PostProcessBuild(-10)]
	public static void OnPostProcessBuildEarly(BuildTarget target, string path)
	{
		
		if(target == BuildTarget.iPhone || target == BuildTarget.Android) {
			//ValidateAndUpdateFacebook();
			
			if(target == BuildTarget.iPhone) {
				//FixUnityPlistAppendBug(path);
			}
		}
	}
	
	[PostProcessScene]
	public static void OnPostprocessScene()
	{
		sharePlusSettings settings = (sharePlusSettings)Resources.Load(sharePlusSettingEditor.settingsFile);
		
		if(settings != null) {
			if(settings.IsValid && settings.IsEnabled) {
				GameObject sharePlusEarlyInitializer = new GameObject("sharePlusEarlyInitializer");
				sharePlusEarlyInitializer.AddComponent<sharePlusEarlyInitializer>();
			}
		}
	}

	public static void SetsharePlusEnabledForTarget(BuildTargetGroup target, bool enabled)
	{
		string targetDefine = "";
		
		if(target == BuildTargetGroup.iPhone) {
			targetDefine = "SHAREPLUS_IPHONE";
		}
		else if(target == BuildTargetGroup.Android) {
			targetDefine = "SHAREPLUS_ANDROID";
		}

		SetScriptingDefineSymbolForTarget(target, targetDefine, enabled);
	}

	private static void PostProcessBuild_iOS(string path, string clientId)
	{
		CreateModFile(path);
		//CreateEveryplayConfig(path);
		//ProcessGlesFiles(path);
		ProcessXCodeProject(path);
		//ProcessInfoPList(path, clientId);
		SetsharePlusEnabledForTarget(BuildTargetGroup.iPhone, true);
	}

	private static void CreateModFile(string path)
	{
		Dictionary<string, object> mod = new Dictionary<string, object>();
		
		List<string> patches = new List<string>();
		List<string> libs = new List<string>();
		List<string> librarysearchpaths = new List<string>();
		librarysearchpaths.Add ("Plugins/sharePlus/iOS/WeChatSDK");
		//libs.Add ("/usr/lib/libz.dylib");
		//libs.Add ("/usr/lib/sqlite3.dylib");
		//libs.Add ("/usr/lib/stdc++.dylib");
		//libs.Add ("/usr/lib/iconv.dylib");
		
		List<string> frameworksearchpaths = new List<string>();
		frameworksearchpaths.Add("Plugins/sharePlus/iOS");
		
		List<string> frameworks = new List<string>();
		frameworks.Add ("CoreFoundation.framework:weak");
		frameworks.Add ("CoreVideo.framework:weak");
		frameworks.Add ("CoreMedia.framework:weak");
		frameworks.Add ("CoreMotion.framework:weak");
		frameworks.Add ("CoreImage.framework:weak");
		frameworks.Add ("CoreText.framework:weak");
		frameworks.Add ("MessageUI.framework:weak");
		frameworks.Add ("Security.framework:weak");
		frameworks.Add ("SystemConfiguration.framework:weak");
		frameworks.Add ("Accounts.framework:weak");
		frameworks.Add ("CoreTelephony.framework:weak");
		frameworks.Add ("MediaPlayer.framework:weak");
		frameworks.Add ("QuartzCore.framework:weak");
		frameworks.Add ("OpenAL.framework:weak");
		frameworks.Add ("OpenGLES.framework:weak");
		frameworks.Add ("AudioToolbox.framework:weak");
		frameworks.Add ("AVFoundation.framework:weak");
		frameworks.Add ("UIKit.framework:weak");
		frameworks.Add ("Foundation.framework:weak");
		frameworks.Add ("CoreGraphics.framework:weak");
		frameworks.Add ("GameKit.framework:weak");
		frameworks.Add ("/usr/lib/libz.dylib");
		frameworks.Add ("/usr/lib/libsqlite3.dylib");
		//frameworks.Add ("/usr/lib/libstdc++.dylib");
		frameworks.Add ("/usr/lib/libiconv.dylib");

		//frameworks.Add("AdSupport.framework:weak");
		//frameworks.Add("AssetsLibrary.framework");
		//frameworks.Add("CoreImage.framework:weak");
		//frameworks.Add("MessageUI.framework");
		//frameworks.Add("Security.framework");
		//frameworks.Add("Social.framework:weak");
		//frameworks.Add("StoreKit.framework");
		//frameworks.Add("Twitter.framework:weak");
		//frameworks.Add("Accounts.framework:weak");
		
		List<string> files = new List<string>();
		files.Add("Plugins/sharePlus/iOS/AiPaiSDK.framework");
		files.Add("Plugins/sharePlus/iOS/AiPaiSDKResource.bundle");
		files.Add("Plugins/sharePlus/iOS/TencentOpenApi_IOS_Bundle.bundle");
		files.Add("Plugins/sharePlus/iOS/TencentOpenAPI.framework");
		files.Add("Plugins/sharePlus/iOS/WeChatSDK");
		//files.Add("Plugins/sharePlus/iOS/delegate.m");
		files.Add("Plugins/sharePlus/iOS/record.m");
		//files.Add("Plugins/sharePlus/iOS/record.h");
		//files.Add("Plugins/sharePlus/iOS/EveryplayGlesSupport.mm");
		//files.Add("Plugins/sharePlus/iOS/EveryplayUnity.h");
		//files.Add("Plugins/sharePlus/iOS/EveryplayUnity.mm");
		//files.Add(System.IO.Path.Combine(path, "sharePlus/EveryplayConfig.h"));
		
		List<string> headerpaths = new List<string>();
		headerpaths.Add("Plugins/sharePlus/iOS");
		headerpaths.Add ("Plugins/sharePlus/iOS/WeChatSDK");
		
		List<string> folders = new List<string>();
		List<string> excludes = new List<string>();
		
		mod.Add("group", "sharePlus");
		mod.Add("patches", patches);
		mod.Add("libs", libs);
		mod.Add("librarysearchpaths", librarysearchpaths);
		mod.Add("frameworksearchpaths", frameworksearchpaths);
		mod.Add("frameworks", frameworks);
		mod.Add("headerpaths", headerpaths);
		mod.Add("files", files);
		mod.Add("folders", folders);
		mod.Add("excludes", excludes);
		
		string jsonMod = sharePlusMiniJSON.Json.Serialize(mod);
		
		string modPath = System.IO.Path.Combine(path, "sharePlus");
		string file = System.IO.Path.Combine(modPath, "sharePlusXCode.projmods");
		
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

	private static void ProcessXCodeProject(string path)
	{
		sharePlus.XCodeEditor.XCProject project = new sharePlus.XCodeEditor.XCProject(path);
		
		string modsPath = System.IO.Path.Combine(path, "sharePlus");
		string[] files = System.IO.Directory.GetFiles(modsPath, "*.projmods", System.IO.SearchOption.AllDirectories);
	
		foreach(string file in files) {
			project.ApplyMod(Application.dataPath,file);
		}
		
		project.Save();
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
}
