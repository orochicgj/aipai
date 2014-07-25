APP_STL:= gnustl_static
MY_WEBRTC_ROOT_PATH := $(call my-dir)
APP_CFLAGS := \
	-I$(MY_WEBRTC_ROOT_PATH)/../  \
	-I$(MY_WEBRTC_ROOT_PATH)/../../ \
	-I$(MY_WEBRTC_ROOT_PATH)/../third_party/protobuf/src/ \
	-I$(MY_WEBRTC_ROOT_PATH)/../third_party/protobuf \

LDFLAGS := $(LDFLAGS) -L$(MY_WEBRTC_ROOT_PATH)/../out/Debug
APP_ABI := armeabi armeabi-v7a
APP_MODULES := libwebrtc_audio_preprocessing
