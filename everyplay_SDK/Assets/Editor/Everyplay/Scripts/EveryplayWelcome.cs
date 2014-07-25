using UnityEngine;
using UnityEditor;
using System.Collections;

public class EveryplayWelcome : EditorWindow
{
    private Texture2D welcomeTexture2d = null;
    private GUIStyle welcomeStyle = null;
//GUISytle是定义GUI样式
    public static void ShowWelcome()
    {
		//EditorGUIUtility.Load会优先在Assets/Editor Default Resources目录下寻找资源，如果找不到，
		//则会在内建的editor resource里面找
        Texture2D texture = (Texture2D)EditorGUIUtility.Load("Everyplay/Images/everyplay-welcome.png");

        if(texture != null) {
		//定义GUI样式
            GUIStyle style = new GUIStyle();
            style.margin = new RectOffset(0, 0, 0, 0);
            style.padding = new RectOffset(0, 0, 0, 0);
            style.alignment = TextAnchor.MiddleCenter;

            if(style != null) {
                EveryplayWelcome window = (EveryplayWelcome)GetWindow(typeof(EveryplayWelcome), true, "Welcome to Everyplay!");
                window.position = new Rect(196, 196, texture.width, texture.height);
                window.minSize = new Vector2(texture.width, texture.height);
                window.maxSize = new Vector2(texture.width, texture.height);
                window.welcomeTexture2d = texture;
                window.welcomeStyle = style;
                window.Show();//显示创建好的窗口，此时窗口什么都不显示，就是一个纯粹的窗口。窗口的内容
            }					//在OnGUI()里面绘制
        }
    }

    void OnGUI() 
    {
        if(welcomeStyle == null || welcomeTexture2d == null) {
            return;
        }

		//画了一个button填满窗口
        if(GUI.Button(new Rect(0, 0, welcomeTexture2d.width, welcomeTexture2d.height), welcomeTexture2d, welcomeStyle)) {
            Close();
            EveryplaySettingsEditor.ShowSettings();
            Application.OpenURL("https://developers.everyplay.com/");
        }
    }
}
