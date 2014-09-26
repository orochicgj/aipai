using UnityEngine;
using System.Collections;
using UnityEditor;

public class sharePlusWelcome : EditorWindow {

	private Texture2D welcomeTexture2D = null;
	private GUIStyle welcomeStyle = null;

	public static void ShowWelcome(){
		Texture2D texture = (Texture2D)EditorGUIUtility.Load ("sharePlus/Images/sharePlus-welcome.png");

		if (texture != null) {
			GUIStyle style = new GUIStyle();
			style.margin = new RectOffset(0,0,0,0);
			style.padding = new RectOffset(0,0,0,0);
			style.alignment = TextAnchor.MiddleCenter;

			if(style != null){
				sharePlusWelcome window = (sharePlusWelcome)GetWindow(typeof(sharePlusWelcome),true,"Welcome to sharePlus");
				window.position = new Rect(196, 196, texture.width, texture.height);
				window.minSize = new Vector2(texture.width, texture.height);
				window.maxSize = new Vector2(texture.width, texture.height);
				window.welcomeStyle = style;
				window.welcomeTexture2D = texture;
				window.Show();
			}
		}
	}

	void OnGUI(){
		if (welcomeStyle == null || welcomeTexture2D == null) {
			return;		
		}
		if (GUI.Button (new Rect (0, 0, welcomeTexture2D.width, welcomeTexture2D.height), welcomeTexture2D, welcomeStyle)) {
			Close();
			sharePlusSettingEditor.ShowSettings();
			Application.OpenURL("http://sdk.aipai.com/");
		}
	}
}
