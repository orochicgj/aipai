using UnityEngine;
using UnityEditor;
using System;
using System.Collections;
using System.IO;

//如果想在Inspector上给脚本绘图，就一定要加上这个属性，不然Inspector上面就只显示脚本的public变量
[CustomEditor(typeof(EveryplaySettings))]
public class EveryplaySettingsEditor : Editor
{
    public const string settingsFile = "EveryplaySettings";
    public const string settingsFileExtension = ".asset";
    public const string testButtonsResourceFile = "everyplay-test-buttons.png";
    private static GUIContent labelClientId = new GUIContent("Client id");
    private static GUIContent labelClientSecret = new GUIContent("Client secret");
    private static GUIContent labelRedirectURI = new GUIContent("Redirect URI");
    private static GUIContent labelIOsSupport = new GUIContent("iOS enabled [?]", "Check to enable Everyplay replay recording on iOS devices");
    private static GUIContent labelAndroidSupport = new GUIContent("Android enabled [?]", "Check to enable Everyplay replay recording on Android devices");
    private static GUIContent labelTestButtons = new GUIContent("Enable test buttons [?]", "Check to overlay easy-to-use buttons for testing Everyplay in your game");
    private EveryplaySettings currentSettings = null;
    private bool iosSupportEnabled;
    private bool androidSupportEnabled;
    private bool testButtonsEnabled;

    [MenuItem("Edit/Everyplay Settings")]
    public static void ShowSettings()
    {
		//Resources.Load只能加载Resources文件夹下面的资源，所以需要通过CreateEveryplaySettings()
		//把脚本添加到Resources文件夹
        EveryplaySettings settingsInstance = (EveryplaySettings)Resources.Load(settingsFile);

        if(settingsInstance == null) {
            settingsInstance = CreateEveryplaySettings();
        }

        if(settingsInstance != null) {
            EveryplayPostprocessor.ValidateAndUpdateFacebook();
            EveryplayLegacyCleanup.Clean(false);
			//Selection用来在编辑器中访问选择的对象
			//设置编辑器当前活动的对象是settingsInstance
            Selection.activeObject = settingsInstance;
        }
    }

    public override void OnInspectorGUI()
    {
        try {
            // Might be null when this gui is open and this file is being reimported
            if(target == null) {
                Selection.activeObject = null;
                return;
            }
			//target是Editor类中一个变量，返回的是当前Inspector中选择的对象，即由
			//Selection.activeObject设置的那个对象
            currentSettings = (EveryplaySettings)target;
            bool showAndroidSettings = CheckForAndroidSDK();

            if(currentSettings != null) {
                EditorGUILayout.HelpBox("1) Enter your game credentials", MessageType.None);

                if(!currentSettings.IsValid) {
                    EditorGUILayout.HelpBox("Invalid or missing game credentials, Everyplay disabled. Check your game credentials at https://developers.everyplay.com/", MessageType.Error);
                }
				//开始GUI水平组布局，返回一个矩形区域。利用这个可以做复合布局
                EditorGUILayout.BeginHorizontal();
				//显示一个标签
                EditorGUILayout.LabelField(labelClientId, GUILayout.Width(108), GUILayout.Height(18));
				//显示标签后面的文本框，并把文本框里面的值赋给EveryplaySettings的clientID
                currentSettings.clientId = TrimmedText(EditorGUILayout.TextField(currentSettings.clientId));
                //结束水平布局
				EditorGUILayout.EndHorizontal();

                EditorGUILayout.BeginHorizontal();
                EditorGUILayout.LabelField(labelClientSecret, GUILayout.Width(108), GUILayout.Height(18));
                currentSettings.clientSecret = TrimmedText(EditorGUILayout.TextField(currentSettings.clientSecret));
                EditorGUILayout.EndHorizontal();

                EditorGUILayout.BeginHorizontal();
                EditorGUILayout.LabelField(labelRedirectURI, GUILayout.Width(108), GUILayout.Height(18));
                currentSettings.redirectURI = TrimmedText(EditorGUILayout.TextField(currentSettings.redirectURI));
                EditorGUILayout.EndHorizontal();

                EditorGUILayout.HelpBox("2) Enable recording on these platforms", MessageType.None);
				
				//开始垂直布局
                EditorGUILayout.BeginVertical();
				
				//用一个Toggle控制是否支持IOS
                iosSupportEnabled = EditorGUILayout.Toggle(labelIOsSupport, currentSettings.iosSupportEnabled);

                if(iosSupportEnabled != currentSettings.iosSupportEnabled) {
					//如果支持就给EverypalySettings的属性赋值
                    currentSettings.iosSupportEnabled = iosSupportEnabled;
					//为对应的平台设置编译标识
                    EveryplayPostprocessor.SetEveryplayEnabledForTarget(BuildTargetGroup.iPhone, currentSettings.iosSupportEnabled);
                    //当currentSettings发生改变，会自动把值保存到硬盘
					EditorUtility.SetDirty(currentSettings);
                }

                if(showAndroidSettings) {
                    androidSupportEnabled = EditorGUILayout.Toggle(labelAndroidSupport, currentSettings.androidSupportEnabled);

                    if(androidSupportEnabled != currentSettings.androidSupportEnabled) {
                        currentSettings.androidSupportEnabled = androidSupportEnabled;
                        EveryplayPostprocessor.SetEveryplayEnabledForTarget(BuildTargetGroup.Android, currentSettings.androidSupportEnabled);
                        EditorUtility.SetDirty(currentSettings);
                    }
                }

                EditorGUILayout.EndVertical();

                EditorGUILayout.HelpBox("3) Try out Everyplay", MessageType.None);

                EditorGUILayout.BeginVertical();
                testButtonsEnabled = EditorGUILayout.Toggle(labelTestButtons, currentSettings.testButtonsEnabled);
                if(testButtonsEnabled != currentSettings.testButtonsEnabled) {
                    currentSettings.testButtonsEnabled = testButtonsEnabled;
                    EditorUtility.SetDirty(currentSettings);
					//根据是否开启测试，确定要不要复制图片
                    EnableTestButtons(testButtonsEnabled);
                }
                EditorGUILayout.EndVertical();
            }
        }
        catch(Exception e) {
            if(e != null) {
            }
        }
    }

    private static string TrimmedText(string txt)
    {
        if(txt != null) {
            return txt.Trim();
        }
        return "";
    }

    private static EveryplaySettings CreateEveryplaySettings()
    {
	//ScriptableObject用来处理不需要依赖游戏对象的对象，最常用的是用来处理只存储数据的资源
        EveryplaySettings everyplaySettings = (EveryplaySettings)ScriptableObject.CreateInstance(typeof(EveryplaySettings));

        if(everyplaySettings != null) {
            if(!Directory.Exists(System.IO.Path.Combine(Application.dataPath, "Plugins/Everyplay/Resources"))) {
                AssetDatabase.CreateFolder("Assets/Plugins/Everyplay", "Resources");
            }
			//把EveryplaySettings脚本创建成资源，因为只有这样才可以用Resources.load加载
            AssetDatabase.CreateAsset(everyplaySettings, "Assets/Plugins/Everyplay/Resources/" + settingsFile + settingsFileExtension);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();

            return everyplaySettings;
        }

        return null;
    }

    public void EnableTestButtons(bool enable) {
        string dstFile = "Plugins/Everyplay/Resources/" + testButtonsResourceFile;
        if(enable) {
            string sourceFile = "Plugins/Everyplay/Images/" + testButtonsResourceFile;
            if(!File.Exists(System.IO.Path.Combine(Application.dataPath, dstFile)) && File.Exists(System.IO.Path.Combine(Application.dataPath, sourceFile))) {
                AssetDatabase.CopyAsset("Assets/" + sourceFile, "Assets/" + dstFile);
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
            }
        }
        else {
            if(File.Exists(System.IO.Path.Combine(Application.dataPath, dstFile))) {
                AssetDatabase.DeleteAsset("Assets/" + dstFile);
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
            }
        }
    }

    public static bool CheckForAndroidSDK()
    {
        if(System.IO.File.Exists(System.IO.Path.Combine(Application.dataPath, "Plugins/Android/everyplay/AndroidManifest.xml")) || System.IO.File.Exists(System.IO.Path.Combine(Application.dataPath, "Plugins/Android/Everyplay/AndroidManifest.xml"))) {
            return true;
        }
        return false;
    }

	//当scriptableObject被销毁的时候会执行
    void OnDisable()
    {
        if(currentSettings != null) {
            EditorUtility.SetDirty(currentSettings);
            currentSettings = null;
        }
    }
}
