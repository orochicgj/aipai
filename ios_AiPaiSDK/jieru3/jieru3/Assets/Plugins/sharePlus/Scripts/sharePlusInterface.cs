using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class sharePlusInterface : MonoBehaviour {
	[DllImport("__Internal")]
	private static extern void setUpWithAppKey(string appKey, string weixinKey, string qqZoneKey);
	[DllImport("__Internal")]
	private static extern bool isSupported();
	[DllImport("__Internal")]
	private static extern bool isRecording();
	[DllImport("__Internal")]
	private static extern bool isPaused();
	[DllImport("__Internal")]
	private static extern void startRecording();
	[DllImport("__Internal")]
	private static extern void stopRecording();
	[DllImport("__Internal")]
	private static extern void pauseRecording();
	[DllImport("__Internal")]
	private static extern void resumeRecording();
	[DllImport("__Internal")]
	private static extern void showControl(bool show);
	[DllImport("__Internal")]
	private static extern void showLibraryView();
	[DllImport("__Internal")]
	private static extern void showWebLibraryView();

	public static void IsetUpWithAppKey(string appKey, string weixinKey, string qqZoneKey){
		setUpWithAppKey( appKey,  weixinKey,  qqZoneKey);
	}

	public static bool IisSupported(){
		return isSupported ();
	}

	public static bool IisRecording(){
		return isRecording ();
	}

	public static bool IisPaused(){
		return isPaused ();
	}

	public static void IstartRecording(){
		startRecording();
	}

	public static void IstopRecording(){
		IstopRecording();
	}

	public static void IpauseRecording(){
		pauseRecording();
	}

	public static void IresumeRecording(){
		resumeRecording();
	}

	public static void IshowControl(bool show){
		showControl(show);
	}

	public static void IshowLibraryView(){
		showLibraryView();
	}

	public static void IshowWebLibraryView(){
		showWebLibraryView();
	}
}
