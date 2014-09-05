#!/bin/sh
adb uninstall com.android.gl2jni
rm -r bin
ndk-build

