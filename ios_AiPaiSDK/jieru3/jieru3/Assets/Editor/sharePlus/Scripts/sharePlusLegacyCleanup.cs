using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;

public class sharePlusLegacyCleanup : AssetPostprocessor {

	void OnPreprocessTexture(){
		if (assetPath.Contains ("Plugins/sharePlus")) {
			TextureImporter textureImporter = (TextureImporter)assetImporter;
			if(textureImporter != null){
				textureImporter.textureFormat = TextureImporterFormat.AutomaticTruecolor;
			}
		}
	}

	static void OnPostprocessAllAssets(string[] importedAssets, string[] deletedAssets, string[] movedAssets, string[] movedFromAssetPaths){
		foreach (string asset in importedAssets) {
			if(asset.Trim().Equals("Assets/Plugins/sharePlus/Scripts/sharePlusLegacy.cs")){
				sharePlusWelcome.ShowWelcome();
				return;
			}		
		}
	}
}
