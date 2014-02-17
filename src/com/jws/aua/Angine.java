/*******************************************************************************
 * Copyright (c) 2012-2020 JWS
 * Jason Work Studio (JWS)
 *
 * All rights reserved.
 *******************************************************************************/
package com.jws.aua;

import android.graphics.Canvas;

/**
 * Lua game engine.
 *
 *
 * Created: Sun Feb 16 00:05:40 2014
 *
 * @author <a href="mailto:enroute.smth@gmail.com">enroute</a>
 * @version 1.0
 */
public class Angine {
    static {
	System.loadLibrary("jua");
    }

    public static native void init();
    public static native void start();
    public static native void restart();
    public static native void stop();
    public static native boolean isRunning();
    public static native boolean update();
    public static native void render(Canvas c);

    public static native void surfaceCreated();
    public static native void surfaceChanged(int format, int width, int height);
    public static native void surfaceDestroyed();
}
