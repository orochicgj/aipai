using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class sharePlus : MonoBehaviour {
	
	private static sharePlus sharePlusInstance = null;
	private static bool flag = false;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnApplicationQuit(){

	}

	public static void Initialize(){
		if (IsRecordingSupported ()) {
			if (sharePlusInstance == null) {
				sharePlusSettings settings = (sharePlusSettings)Resources.Load ("sharePlusSettings");
				if (settings != null) {
					if (settings.IsEnabled != null) {
						GameObject sharePlusGameObject = new GameObject ("sharePlus");
						if (sharePlusGameObject != null) {
							sharePlusInstance = sharePlusGameObject.AddComponent<sharePlus> ();
							if (sharePlusInstance != null) {
								sharePlusInterface.IsetUpWithAppKey(settings.key, settings.tencent_weixin, settings.tencent_kongjian);
							}
							DontDestroyOnLoad (sharePlusGameObject);
						}
					}
				}
			}
		}
	}
	/*
	private static void AddTestButtons(GameObject gameObject){
		Texture2D textureAtlas = (Texture2D)Resources.Load ("everyplay-test-buttons",typeof(Texture2D));
		if (textureAtlas != null) {
			sharePlusRecButtons recButtons = gameObject.AddComponent<sharePlusRecButtons>();
			if(recButtons != null){
				//recButtons.atlasTexture = textureAtlas;
			}
		}
	}


	public static void StarRecording(){

	}

	public static void StopRecording(){

	}

	public static void PauseRecording(){

	}

	public static void ResumeRecording(){

	}

	public static void ShowControl(){

	}
*/	
	public static bool IsRecordingSupported(){
		if (sharePlusInstance != null) {
			//return sharePlusIsRecordingSupported();
			return true;
		}
		return true;
	}


}
