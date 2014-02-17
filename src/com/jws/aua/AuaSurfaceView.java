/*******************************************************************************
 * Copyright (c) 2012-2020 JWS
 * Jason Work Studio (Shenzhen)
 *
 * All rights reserved.
 *******************************************************************************/
package com.jws.aua;

import android.content.Context;
import android.graphics.Canvas;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Describe class AuaSurfaceView here.
 *
 *
 * Created: Sat Feb 15 22:13:15 2014
 *
 * @author <a href="mailto:enroute.smth@gmail.com">enroute</a>
 * @version 1.0
 */
public class AuaSurfaceView extends SurfaceView implements SurfaceHolder.Callback {

    // Implementation of android.view.SurfaceHolder$Callback
    public void surfaceCreated(SurfaceHolder holder) {
	m_engine.surfaceCreated();
    }

    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
	m_engine.surfaceChanged(format, width, height);
    }

    public void surfaceDestroyed(SurfaceHolder holder) {
	m_engine.surfaceDestroyed();
    }

    // constructor
    public AuaSurfaceView(Context context) {
	super(context);
    }

    // private variables
    private Angine m_engine;

    // draw thread
    class AuaDrawThread extends Thread {
	private SurfaceHolder holder;

	public AuaDrawThread(SurfaceHolder h) {
	    holder = h;
	}
	
	@Override
	public void run()
	{
	    Canvas c = null;
	    while( true ) {
		if(! m_engine.update()) {
		    continue;
		}

		try {
		    synchronized(holder) {
			c = holder.lockCanvas();
			// do the drawing
			
			m_engine.render(c);
		    }
		}
		catch(Exception e) {
		    e.printStackTrace();
		}
		finally {
		    if(null != c) {
			holder.unlockCanvasAndPost(c);
		    }
		}
	    }
	}
    }
}
