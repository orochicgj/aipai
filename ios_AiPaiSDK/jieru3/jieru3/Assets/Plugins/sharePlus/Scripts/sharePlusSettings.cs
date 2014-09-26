using UnityEngine;
using System.Collections;

public class sharePlusSettings : ScriptableObject {

	public string key;
	public string tencent_kongjian;
	public string tencent_weixin;

	public bool iosSupportEnabled;
	public bool showControl;
	public bool androidSupportEnabled;
	public bool testButtonsEnabled;

	public bool IsEnabled{
		get{
			#if UNITY_IPHONE
				return iosSupportEnabled;
			#elif UNITY_ANDROID
				return androidSupportEnabled;
			#else
				return false;
			#endif
		}
	}

	public bool IsValid{
		get{
			if(key != null){
				if(key.Trim().Length > 0){
					return true;
				}
			}
			return false;
		}
	}
}
