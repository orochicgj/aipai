package com.example.ninetobitmap;

import java.nio.ByteBuffer;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.NinePatch;
import android.graphics.Rect;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.NinePatchDrawable;
import android.os.Bundle;
import android.os.Environment;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;


public class MainActivity extends ActionBarActivity {
	
	static Bitmap bmp;
	static Drawable drawable;
	static Canvas canvas;
	static ByteBuffer buffer;
	static byte []array;
	private Resources mResources;
	NinePatchDrawable npd;
	
	ImageView iv;
	ImageView iv2;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		if (savedInstanceState == null) {
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
		draw9();
		draw99();
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			return rootView;
		}
	}
	
	static public void nineToBitmap(String path,int width,int height,String colorFormat){
		//draw 9-patch to bitmap
		/*
		bmp = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		drawable = getResources().getDrawable(R.drawable.abc_ab_solid_dark_holo);
		canvas = new Canvas(bmp);
		drawable.setBounds(0, 0, canvas.getWidth(), canvas.getHeight());
		drawable.draw(canvas);
		//*/
//		path = Environment.getExternalStorageDirectory() + "b.9.png";
//		bmp = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
//		drawable = Drawable.createFromPath(path);
//		canvas = new Canvas(bmp);
//		drawable.setBounds(0, 0, canvas.getWidth(), canvas.getHeight());
//		drawable.draw(canvas);
//		//covert bitmap to byte array
//		//int bytes = bmp.getByteCount();
//		//buffer = ByteBuffer.allocate(bytes);
//		bmp.copyPixelsToBuffer(buffer);
//		array = buffer.array();
	}
	
	static public byte[]  getBuffer(byte[] array){
		return array;
	}
	
	public void draw9(){
		String path = Environment.getExternalStorageDirectory() + "/t.png";
		iv = (ImageView)findViewById(R.id.iv);
		Log.d("nine", "path = "+path);
		bmp = BitmapFactory.decodeFile(path);
		NinePatch np = new NinePatch(bmp, bmp.getNinePatchChunk(),null);
		npd = new NinePatchDrawable(getResources(), np);
		npd.setBounds(0, 0, 100, 200);
		Bitmap b;
		b = Bitmap.createBitmap(100, 200, Bitmap.Config.ARGB_8888);
		canvas = new Canvas(b);
		npd.draw(canvas);
		
		//covert bitmap to byte array
		int bytes = b.getByteCount();
		buffer = ByteBuffer.allocate(bytes);
		b.copyPixelsToBuffer(buffer);
		array = buffer.array();
		iv.setImageBitmap(b);
	}
	
	public void draw99(){
		iv2 = (ImageView)findViewById(R.id.iv2);
		bmp = Bitmap.createBitmap(100, 200, Bitmap.Config.ARGB_8888);
		drawable = getResources().getDrawable(R.drawable.bbb);
		canvas = new Canvas(bmp);
		drawable.setBounds(0, 0, canvas.getWidth(), canvas.getHeight());
		drawable.draw(canvas);
		iv2.setImageBitmap(bmp);
	}
	
	static{
		System.loadLibrary("test");
	}

}
