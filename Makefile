.PHONY: all

all:bin/Aua-debug.apk

libs/armeabi-v7a/libjua.so: jni/$(wildcard *.c)
	ndk-build

bin/Aua-debug.apk: $(wildcard src/com/jws/*/*.java) libs/armeabi-v7a/libjua.so
	ant debug

test:bin/Aua-debug.apk
	adb install -r bin/Aua-debug.apk
	adb shell am start -n com.jws.aua/.AuaActivity
