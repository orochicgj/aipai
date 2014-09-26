using UnityEngine;
using System.Collections;
using UnityEditor;
using System;
using System.IO;

[CustomEditor(typeof(sharePlusSettings))]
public class sharePlusSettingEditor : Editor {

	public const string settingsFile = "sharePlusSettings";
	public const string settingsFileExtension = ".asset";
	public const string testButtonsResourceFile = "sharePlus-test-buttons.png";
	private static GUIContent labelKey = new GUIContent("Key");
	private static GUIContent labelKongjian = new GUIContent("QQ zone");
	private static GUIContent labelWeixin = new GUIContent("WeChart");
	private static GUIContent labelIOsSupport = new GUIContent("iOS enabled [?]", "Check to enable sharePlus replay recording on iOS devices");
	private static GUIContent labelShowControl = new GUIContent ("show control [?]", "Check to show control view");
	private static GUIContent labelAndroidSupport = new GUIContent("Android enabled [?]", "Check to enable sharePlus replay recording on Android devices");
	private static GUIContent labelTestButtons = new GUIContent("Enable test buttons [?]", "Check to overlay easy-to-use buttons for testing sharePlus in your game");
	private sharePlusSettings currentSettings = null;
	private bool iosSupportEnabled;
	private bool showControl;
	private bool androidSupportEnabled;
	private bool testButtonsEnabled;

	[MenuItem("Edit/sharePlus Settings")]
	public static void ShowSettings()
	{
		sharePlusSettings settingsInstance = (sharePlusSettings)Resources.Load(settingsFile);
		
		if(settingsInstance == null) {
			settingsInstance = CreateEveryplaySettings();
		}
		
		if(settingsInstance != null) {
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
			
			currentSettings = (sharePlusSettings)target;
			//bool showAndroidSettings = CheckForAndroidSDK();
			bool showAndroidSettings = false;
			
			if(currentSettings != null) {
				EditorGUILayout.HelpBox("1) Enter your game credentials", MessageType.None);
				
				if(!currentSettings.IsValid) {
					EditorGUILayout.HelpBox("Invalid or missing game credentials, sharePlus disabled. Check your game credentials at sdk.aipai.com", MessageType.Error);
				}
				
				EditorGUILayout.BeginHorizontal();
				EditorGUILayout.LabelField(labelKey, GUILayout.Width(108), GUILayout.Height(18));
				currentSettings.key = TrimmedText(EditorGUILayout.TextField(currentSettings.key));
				EditorGUILayout.EndHorizontal();
				
				EditorGUILayout.BeginHorizontal();
				EditorGUILayout.LabelField(labelKongjian, GUILayout.Width(108), GUILayout.Height(18));
				currentSettings.tencent_kongjian = TrimmedText(EditorGUILayout.TextField(currentSettings.tencent_kongjian));
				EditorGUILayout.EndHorizontal();
				
				EditorGUILayout.BeginHorizontal();
				EditorGUILayout.LabelField(labelWeixin, GUILayout.Width(108), GUILayout.Height(18));
				currentSettings.tencent_weixin = TrimmedText(EditorGUILayout.TextField(currentSettings.tencent_weixin));
				EditorGUILayout.EndHorizontal();
				
				EditorGUILayout.HelpBox("2) Enable recording on these platforms", MessageType.None);
				
				EditorGUILayout.BeginVertical();
				
				iosSupportEnabled = EditorGUILayout.Toggle(labelIOsSupport, currentSettings.iosSupportEnabled);
				
				if(iosSupportEnabled != currentSettings.iosSupportEnabled) {
					currentSettings.iosSupportEnabled = iosSupportEnabled;
					sharePlusPostprocessor.SetsharePlusEnabledForTarget(BuildTargetGroup.iPhone, currentSettings.iosSupportEnabled);
					EditorUtility.SetDirty(currentSettings);
				}

				showControl = EditorGUILayout.Toggle(labelShowControl,currentSettings.showControl);

				if(showControl != currentSettings.showControl){
					currentSettings.showControl = showControl;
					EditorUtility.SetDirty(currentSettings);
				}
				
				if(showAndroidSettings) {
					androidSupportEnabled = EditorGUILayout.Toggle(labelAndroidSupport, currentSettings.androidSupportEnabled);
					
					if(androidSupportEnabled != currentSettings.androidSupportEnabled) {
						currentSettings.androidSupportEnabled = androidSupportEnabled;
						sharePlusPostprocessor.SetsharePlusEnabledForTarget(BuildTargetGroup.Android, currentSettings.androidSupportEnabled);
						EditorUtility.SetDirty(currentSettings);
					}
				}
				
				EditorGUILayout.EndVertical();
				
				EditorGUILayout.HelpBox("3) Try out sharePlus", MessageType.None);
				
				EditorGUILayout.BeginVertical();
				testButtonsEnabled = EditorGUILayout.Toggle(labelTestButtons, currentSettings.testButtonsEnabled);
				if(testButtonsEnabled != currentSettings.testButtonsEnabled) {
					currentSettings.testButtonsEnabled = testButtonsEnabled;
					EditorUtility.SetDirty(currentSettings);
					//EnableTestButtons(testButtonsEnabled);
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

	private static sharePlusSettings CreateEveryplaySettings()
	{
		sharePlusSettings sharePlusSettings = (sharePlusSettings)ScriptableObject.CreateInstance(typeof(sharePlusSettings));
		
		if(sharePlusSettings != null) {
			if(!Directory.Exists(System.IO.Path.Combine(Application.dataPath, "Plugins/sharePlus/Resources"))) {
				AssetDatabase.CreateFolder("Assets/Plugins/sharePlus", "Resources");
			}
			
			AssetDatabase.CreateAsset(sharePlusSettings, "Assets/Plugins/sharePlus/Resources/" + settingsFile + settingsFileExtension);
			AssetDatabase.SaveAssets();
			AssetDatabase.Refresh();
			
			return sharePlusSettings;
		}
		
		return null;
	}
}
