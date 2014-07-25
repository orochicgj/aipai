LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include $(LOCAL_PATH)/../android-webrtc.mk


$(warning $(LOCAL_PATH))
PPP_PATH := ../third_party/protobuf/

$(info my_path = $(PPP_PATH))
$(warning $(PPP_PATH))
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libprotobuf_lite
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := \
	$(PPP_PATH)src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc \
	$(PPP_PATH)src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc \
	$(PPP_PATH)src/google/protobuf/unknown_field_set.cc \
	$(PPP_PATH)src/google/protobuf/stubs/common.cc \
	$(PPP_PATH)src/google/protobuf/stubs/once.cc \
	$(PPP_PATH)src/google/protobuf/extension_set.cc \
	$(PPP_PATH)src/google/protobuf/generated_message_util.cc \
	$(PPP_PATH)src/google/protobuf/message_lite.cc \
	$(PPP_PATH)src/google/protobuf/repeated_field.cc \
	$(PPP_PATH)src/google/protobuf/wire_format_lite.cc \
	$(PPP_PATH)src/google/protobuf/io/coded_stream.cc \
	$(PPP_PATH)src/google/protobuf/io/zero_copy_stream.cc \
	$(PPP_PATH)src/google/protobuf/io/zero_copy_stream_impl_lite.cc


LOCAL_CFLAGS := $(MY_WEBRTC_COMMON_DEFS) 

LOCAL_C_INCLUDES := \
	$(PPP_PATH)src/google/protobuf

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libdl \
    libstlport

ifndef NDK_ROOT
include external/stlport/libstlport.mk
endif
include $(BUILD_STATIC_LIBRARY)
$(info end)
