package com.jws.aua;

public class Jua
{
    // load library
    static {
	System.loadLibrary("jua");
    }

    // init lua
    public static native void init();

    // free lua
    public static native void free();

    // get lua output
    public static native void getOutput();

    // run lua scripts by string
    public static native void doString(String script);

    // run lua script by file
    public static native void doFile(String file);
}
