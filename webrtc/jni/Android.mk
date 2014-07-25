MMM_PATH := $(call my-dir)

include $(MMM_PATH)/android-protobuf.mk
include $(MMM_PATH)/audioproc_debug.mk
include $(MMM_PATH)/../Android.mk

__ndk_modules.webrtc_audio_preprocessing.WHOLE_STATIC_LIBRARIES := $(__ndk_modules.webrtc_audio_preprocessing.WHOLE_STATIC_LIBRARIES) $(call strip-lib-prefix, libprotobuf_lite libaudioproc_debug)

