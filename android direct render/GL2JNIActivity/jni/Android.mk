# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libgl2jni
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := gl_code.cpp native.cpp
LOCAL_LDLIBS    := -llog -lGLESv2 -landroid -lEGL -lui
LOCAL_C_INCLUDES := E:/Android/manifest/frameworks/base/include/ \
				    E:/Android/manifest/hardware/libhardware/include \
				    E:/Android/manifest/system/core/include \
				    E:/Android/manifest/frameworks/base/native/include/ \
				    E:/Android/manifest/frameworks/native/include  \
				    E:/Android/manifest/frameworks/base/opengl/include/

include $(BUILD_SHARED_LIBRARY)
