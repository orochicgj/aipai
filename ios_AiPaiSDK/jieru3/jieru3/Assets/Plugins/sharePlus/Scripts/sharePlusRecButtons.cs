using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/*

public class sharePlusRecButtons : MonoBehaviour {

	public Texture2D atlasTexture;

	private float containerScaling = 1.0f;

	private TextureAtlasSrc shareVideoAtlasSrc;
	private TextureAtlasSrc stopRecordingAtlasSrc;
	private TextureAtlasSrc startRecordingAtlasSrc;
	private TextureAtlasSrc bgHeaderAtlasSrc;
	private TextureAtlasSrc bgFooterAtlasSrc;
	private TextureAtlasSrc bgAtlasSrc;
	private TextureAtlasSrc buttonAtlasSrc;

	private int buttonTitleHorizontalMargin = 16;
	private int buttonTitleVerticalMargin = 20;
	private int buttonMargin = 8;
	private const int atlasPadding = 2;
	private const int atlasWidth = 256;
	private const int atlasHeight = 256;

	private Button shareVideoButton;
	private Button startRecordingButton;
	private Button stopRecordingButton;

	private List<Button> visibleButtons;



	private class TextureAtlasSrc
	{
		public Rect atlasRect;
		public Rect normalizedAtlasRect;
		
		public TextureAtlasSrc(int width, int height, int x, int y, float scale)
		{
			atlasRect.x = x + atlasPadding;
			atlasRect.y = y + atlasPadding;
			atlasRect.width = width * scale;
			atlasRect.height = height * scale;
			normalizedAtlasRect.width = width / (float)atlasWidth;
			normalizedAtlasRect.height = height / (float)atlasHeight;
			normalizedAtlasRect.x = atlasRect.x / (float)atlasWidth;
			normalizedAtlasRect.y = 1.0f - (atlasRect.y + height) / (float)atlasHeight;
		}
	}

	private delegate void ButtonTapped();

	private class Button
	{
		public bool enabled;
		public Rect screenRect;
		public TextureAtlasSrc bg;
		public TextureAtlasSrc title;
		//public ButtonTapped onTap;
		
		public Button(TextureAtlasSrc bg, TextureAtlasSrc title, ButtonTapped buttonTapped)
		{
			this.enabled = true;
			this.bg = bg;
			this.title = title;
			this.screenRect.width = bg.atlasRect.width;
			this.screenRect.height = bg.atlasRect.height;
			this.onTap = buttonTapped;
		}
	}

	void Awake()
	{
		// Scale by resolution
		containerScaling = GetScalingByResolution();
		
		// Texture atlas sources
		//editVideoAtlasSrc = new TextureAtlasSrc(112, 19, 0, 0, containerScaling);
		//faceCamAtlasSrc = new TextureAtlasSrc(103, 19, 116, 0, containerScaling);
		//openEveryplayAtlasSrc = new TextureAtlasSrc(178, 23, 0, 23, containerScaling);
		shareVideoAtlasSrc = new TextureAtlasSrc(134, 19, 0, 50, containerScaling);
		startRecordingAtlasSrc = new TextureAtlasSrc(171, 23, 0, 73, containerScaling);
		stopRecordingAtlasSrc = new TextureAtlasSrc(169, 23, 0, 100, containerScaling);
		//facecamToggleOnAtlasSrc = new TextureAtlasSrc(101, 42, 0, 127, containerScaling);
		//facecamToggleOffAtlasSrc = new TextureAtlasSrc(101, 42, 101, 127, containerScaling);
		bgHeaderAtlasSrc = new TextureAtlasSrc(256, 9, 0, 169, containerScaling);
		bgFooterAtlasSrc = new TextureAtlasSrc(256, 9, 0, 169, containerScaling);
		bgAtlasSrc = new TextureAtlasSrc(256, 6, 0, 178, containerScaling);
		buttonAtlasSrc = new TextureAtlasSrc(220, 64, 0, 190, containerScaling);
		
		buttonTitleHorizontalMargin = Mathf.RoundToInt(buttonTitleHorizontalMargin * containerScaling);
		buttonTitleVerticalMargin = Mathf.RoundToInt(buttonTitleVerticalMargin * containerScaling);
		buttonMargin = Mathf.RoundToInt(buttonMargin * containerScaling);
		
		// Buttons
		shareVideoButton = new Button(buttonAtlasSrc, shareVideoAtlasSrc, ShareVideo);
		//editVideoButton = new Button(buttonAtlasSrc, editVideoAtlasSrc, EditVideo);
		//openEveryplayButton = new Button(buttonAtlasSrc, openEveryplayAtlasSrc, OpenEveryplay);
		startRecordingButton = new Button(buttonAtlasSrc, startRecordingAtlasSrc, StartRecording);
		stopRecordingButton = new Button(buttonAtlasSrc, stopRecordingAtlasSrc, StopRecording);
		//faceCamToggleButton = new ToggleButton(buttonAtlasSrc, faceCamAtlasSrc, FaceCamToggle, facecamToggleOnAtlasSrc, facecamToggleOffAtlasSrc);
		
		visibleButtons = new List<Button>();
		
		// Use header texture for footer by flipping it
		bgFooterAtlasSrc.normalizedAtlasRect.y = bgFooterAtlasSrc.normalizedAtlasRect.y + bgFooterAtlasSrc.normalizedAtlasRect.height;
		bgFooterAtlasSrc.normalizedAtlasRect.height = -bgFooterAtlasSrc.normalizedAtlasRect.height;
		
		// Set initially visible buttons
		SetButtonVisible(startRecordingButton, true);
		//SetButtonVisible(openEveryplayButton, true);
		//SetButtonVisible(faceCamToggleButton, true);
		
		// Set initially
		if(!sharePlus.IsRecordingSupported()) {
			startRecordingButton.enabled = false;
			stopRecordingButton.enabled = false;
		}
		
		//Everyplay.RecordingStarted += RecordingStarted;
		//Everyplay.RecordingStopped += RecordingStopped;
		//Everyplay.ReadyForRecording += ReadyForRecording;
		//Everyplay.FaceCamRecordingPermission += FaceCamRecordingPermission;
	}

	private float GetScalingByResolution(){
		int high = Mathf.Max (Screen.height, Screen.width);
		int low = Mathf.Min (Screen.height, Screen.width);

		if (high < 640 || (high == 1024 && low == 768)) {
			return 0.5f;		
		}
		return 1.0f;
	}

	private void SetButtonVisible(Button button, bool visible)
	{
		if(visibleButtons.Contains(button)) {
			if(!visible) {
				visibleButtons.Remove(button);
			}
		}
		else {
			if(visible) {
				visibleButtons.Add(button);
			}
		}
	}

	private void ShareVideo(){

	}

	private void StartRecording(){

	}

	private void StopRecording(){

	}
}
///*/