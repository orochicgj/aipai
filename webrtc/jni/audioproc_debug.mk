LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include $(LOCAL_PATH)/../android-webrtc.mk


$(warning $(LOCAL_PATH))
PPP_PATH := ../

$(info my_path = $(PPP_PATH))
$(warning $(PPP_PATH))
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libaudioproc_debug
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := \
	$(PPP_PATH)out/Debug/gen/protoc_out/webrtc/audio_processing/debug.pb.cc


LOCAL_CFLAGS := $(MY_WEBRTC_COMMON_DEFS) -DLIBPROTOBUF_EXPORTS -DPROTOBUF_USE_DLLS -DGOOGLE_PROTOBUF_NO_RTTI -DGOOGLE_PROTOBUF_NO_STATIC_INITIALIZER

LOCAL_C_INCLUDES := \
	$(PPP_PATH)out/Debug/gen/protoc_out/webrtc/audio_processing/ 

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libdl \
    libstlport

ifndef NDK_ROOT
include external/stlport/libstlport.mk
endif
include $(BUILD_STATIC_LIBRARY)
$(info end)
