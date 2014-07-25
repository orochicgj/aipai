using UnityEngine;
using UnityEditor;
using System.IO;
using System.Collections;

public class EveryplayLegacyCleanup : AssetPostprocessor
{
    private static string[] filesToRemove = {
            "Editor/PostprocessBuildPlayer_EveryplaySDK",
            "Editor/UpdateXcodeEveryplay.pyc",
            "Plugins/iOS/EveryplayGlesSupport.mm",
            "Plugins/iOS/EveryplayGlesSupport.h",
            "Plugins/iOS/EveryplayUnity.mm",
            "Plugins/iOS/EveryplayUnity.h"
    };
    private const string oldPrefab = "Plugins/Everyplay/Everyplay.prefab";
    private const string newTestPrefab = "Plugins/Everyplay/Helpers/EveryplayTest.prefab";

    void OnPreprocessTexture()
    {
        // Don't compress Everyplay textures, makes importing faster
		//assetPath是AssetPostprocessor中一个只读变量。他是一个string类型，代表导入资源的文件结构（路径）
        if(assetPath.Contains("Plugins/Everyplay")) {
			//assetImporter是AssetPostprocessor中资源导入器的引用。把它赋值给TextureImporter的对象
			//textureImporter，就能通过textureImporter来修改纹理导入时的属性了
            TextureImporter textureImporter = (TextureImporter)assetImporter;
            if(textureImporter != null) {
				//把纹理导入时的格式设置为AutomaticTruecolor，这是一种非压缩真彩格式
                textureImporter.textureFormat = TextureImporterFormat.AutomaticTruecolor;
            }
        }

        // Legacy clean (moving asset) often fails during package import, try to do it a couple of times pre import and one time post import
        if(assetPath.Contains("Plugins/Everyplay/Images")) {
            Clean(true);
        }
    }

    static void OnPostprocessAllAssets(string[] importedAssets, string[] deletedAssets, string[] movedAssets, string[] movedFromAssetPaths)
    {
        // Legacy clean (moving asset) often fails during package import, try to do it a couple of times pre import and one time post import
        //这是一个回调函数，importedAssets里面包含了导入资源的目录结构
		foreach(string asset in importedAssets) {
			//如果找到EveryplayLegacy.cs脚本，说明导入sdk成功，弹出欢迎界面
            if(asset.Trim().Equals("Assets/Plugins/Everyplay/Scripts/EveryplayLegacy.cs")) {
                Clean(true);
                EveryplayWelcome.ShowWelcome();
                return;
            }
        }
    }

    public static void Clean(bool silenceErrors)
    {
        foreach(string fileName in filesToRemove) {
            if(File.Exists(System.IO.Path.Combine(Application.dataPath, fileName))) {
                AssetDatabase.DeleteAsset(System.IO.Path.Combine("Assets", fileName));
                Debug.Log("Removed legacy Everyplay file: " + fileName);
            }
        }

        if(File.Exists(System.IO.Path.Combine(Application.dataPath, oldPrefab))) {
            if(File.Exists(System.IO.Path.Combine(Application.dataPath, newTestPrefab))) {
                AssetDatabase.DeleteAsset(System.IO.Path.Combine("Assets", oldPrefab));
                Debug.Log("Removed legacy Everyplay prefab: " + oldPrefab);
            }
            else {
                string src = System.IO.Path.Combine("Assets", oldPrefab);
                string dst = System.IO.Path.Combine("Assets", newTestPrefab);
				//AssetDatabase.ValidateMoveAsset(src, dst)检查资源能否从一个文件夹移动到另一个文件夹，
				//如果可以就返回一个空字符串。AssetDatabase.MoveAsset(src, dst)就是移动资源，成功也是返
				//回一个空字符串
                if((AssetDatabase.ValidateMoveAsset(src, dst) == "") && (AssetDatabase.MoveAsset(src, dst) == "")) {
                    Debug.Log("Renamed and updated legacy Everyplay prefab " + oldPrefab + " to " + newTestPrefab);
                }
                else if(!silenceErrors) {
                    Debug.LogError("Updating the old Everyplay prefab failed. Please rename Plugins/Everyplay/Everyplay prefab to EveryplayTest and move it to the Plugins/Everyplay/Everyplay/Helpers folder.");
                }
            }
        }
    }
}
