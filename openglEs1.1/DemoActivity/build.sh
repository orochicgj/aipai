#!/bin/bash
adb uninstall com.example.SanAngeles
ndk-build clean
ndk-build
ant clean
ant debug
adb install ./bin/SanAngeles-debug.apk