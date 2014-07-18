package com.example.mediacodec2;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

import android.media.MediaCodec;
import android.media.MediaCodecInfo;
import android.media.MediaCodecList;
import android.media.MediaFormat;
import android.os.Environment;
import android.util.Log;

import com.coremedia.iso.boxes.Container;
import com.googlecode.mp4parser.FileDataSourceImpl;
import com.googlecode.mp4parser.authoring.Movie;
import com.googlecode.mp4parser.authoring.builder.DefaultMp4Builder;
import com.googlecode.mp4parser.authoring.tracks.H264TrackImpl;

public class Encode {
	private static final String TAG = "mediacodec2";
	private MediaCodec mediaCodec;
	private BufferedOutputStream outputStream;
	
	int mWidth = 320;
	int mHeight = 240;
	
	// parameters for the encoder
    private static final String MIME_TYPE = "video/avc";    // H.264 Advanced Video Coding
    private static final int FRAME_RATE = 15;               // 15fps
    private static final int IFRAME_INTERVAL = 10;          // 10 seconds between I-frames
    private static final int NUM_FRAMES = 60;  
    private int mBitRate = 200000;
	
    Encode(){
    	File f = new File(Environment.getExternalStorageDirectory(), "Download/video_encoded.h264");
    	Log.d("path", "path = " + f);
    	try {
            outputStream = new BufferedOutputStream(new FileOutputStream(f));
            Log.i("AvcEncoder", "outputStream initialized");
        } catch (Exception e){ 
            e.printStackTrace();
        }
    }
    
    public void encodeToFile(){
    	Log.d("beforePrepare", "beforePrepare");
    	prepareEncode();
    	int size = mWidth * mHeight * 12 / 8;
    	byte buffer[] = new byte[size];
    	long frameDuration = 1000000 / FRAME_RATE;
    	Log.d("afterPrepare", "afterPrepare");
    	for (int i = 0; i < NUM_FRAMES ; i++) {
    		fillYUVFrame(buffer, mWidth, mHeight, i);
    		writeVideo(buffer, i * frameDuration);
        }

    	realeseEncode();
    	
    }
    
    private void fillYUVFrame(byte[] frame, int w, int h, int index) {
    	int x, y, i;

        i = index;

        /* Y */
        for (y = 0; y < h; y++) {
            for (x = 0; x < w; x++) {
            	frame[y * w + x] = (byte)(x + y + i * 3);
            }
        }
        int uvIndex = w * h;
        /* Cb and Cr */
        for (y = 0; y < h / 2; y++) {
            for (x = 0; x < w / 2; x += 2) {
            	frame[uvIndex + y * w + x] = (byte)(128 + y + i * 2);
                frame[uvIndex + y * w + x+1] = (byte)(64 + x + i * 5);
            }
        }
    }
    
    public void writeVideo(byte[] data, long times){
    	final int TIMEOUT_USEC = 100000;
    	try {
            ByteBuffer[] inputBuffers = mediaCodec.getInputBuffers();
            ByteBuffer[] outputBuffers = mediaCodec.getOutputBuffers();
            int inputBufferIndex = mediaCodec.dequeueInputBuffer(-1);
            if (inputBufferIndex >= 0) {
                ByteBuffer inputBuffer = inputBuffers[inputBufferIndex];
                inputBuffer.clear();
                inputBuffer.put(data);
                mediaCodec.queueInputBuffer(inputBufferIndex, 0, data.length, times, 0);
            }

            MediaCodec.BufferInfo bufferInfo = new MediaCodec.BufferInfo();
            int outputBufferIndex = mediaCodec.dequeueOutputBuffer(bufferInfo,0);
            while (outputBufferIndex >= 0) {
                ByteBuffer outputBuffer = outputBuffers[outputBufferIndex];
                byte[] outData = new byte[bufferInfo.size];
                outputBuffer.get(outData);
                outputStream.write(outData, 0, outData.length);
                Log.i("AvcEncoder", outData.length + " bytes written");

                mediaCodec.releaseOutputBuffer(outputBufferIndex, false);
                outputBufferIndex = mediaCodec.dequeueOutputBuffer(bufferInfo, 0);

            }
        } catch (Throwable t) {
            t.printStackTrace();
        }

    }
    
    public void prepareEncode(){
    	mediaCodec = MediaCodec.createEncoderByType(MIME_TYPE);
		MediaFormat mediaFormat = MediaFormat.createVideoFormat(MIME_TYPE, mWidth, mHeight);
		mediaFormat.setInteger(MediaFormat.KEY_BIT_RATE, mBitRate);
		mediaFormat.setInteger(MediaFormat.KEY_FRAME_RATE, FRAME_RATE);
		//mediaFormat.setInteger(MediaFormat.KEY_COLOR_FORMAT, MediaCodecInfo.CodecCapabilities.COLOR_FormatYUV420Planar);
		mediaFormat.setInteger(MediaFormat.KEY_COLOR_FORMAT, MediaCodecInfo.CodecCapabilities.COLOR_FormatYUV420SemiPlanar );
		mediaFormat.setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, IFRAME_INTERVAL);
		mediaCodec.configure(mediaFormat, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE);
		mediaCodec.start();
    }
   
    public void realeseEncode(){
    	mediaCodec.stop();
    	mediaCodec.release();
    	try {
			outputStream.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	try {
			outputStream.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	Log.i("realese", "realese");
    }
    
    public void onGetMediaCodecInfo()  {
    	int numCodecs = MediaCodecList.getCodecCount();
    	for (int i = 0; i < numCodecs; i++) {
    		MediaCodecInfo info = MediaCodecList.getCodecInfoAt(i);
    		if (!info.isEncoder()) {
    			continue;
    		}
    		String[] types = info.getSupportedTypes();
    		for (String type : types) {
				Log.d(TAG, "support type: " + type);
				MediaCodecInfo.CodecCapabilities capabilities = info.getCapabilitiesForType(type);
				for (int format : capabilities.colorFormats) {
					Log.d(TAG, "color format: " + format);
				}
			}
    		Log.d(TAG, "---------------");
    	}
    }
    
    public void mp4Parser() throws FileNotFoundException, IOException{
    	H264TrackImpl h264Track = new H264TrackImpl(new FileDataSourceImpl("/mnt/sdcard/Download/video_encoded.h264"));
    	Movie m = new Movie();
    	m.addTrack(h264Track);
    	
    	Container out = new DefaultMp4Builder().build(m);
        FileOutputStream fos = new FileOutputStream(new File("/mnt/sdcard/Download/h264_output.mp4"));
        FileChannel fc = fos.getChannel();
        out.writeContainer(fc);
        fos.close();
    	
    }
    
    
}