using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class test1 : MonoBehaviour {

	string str = "null";
	public sharePlusSettings settings ;
	// Use this for initialization
	void Start () {
		settings = (sharePlusSettings)Resources.Load ("sharePlusSettings");
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnGUI(){
		GUI.Label (new Rect(200,200,200,200),str);
		if(GUI.Button(new Rect(0,0,100,50),"showlibrary")){
			str = "e = " + settings.key + "||" + settings.tencent_weixin + "||" + settings.tencent_kongjian;
			//sharePlusInterface.IshowLibraryView();
		}
		if (GUI.Button (new Rect (200, 0, 100, 50), "showwebview")) {
			sharePlusInterface.IshowWebLibraryView();
		}
	}
}
