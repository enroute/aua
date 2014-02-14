package com.jws.aua;

import android.app.Activity;
import android.os.Bundle;

import com.jws.aua.Jua;

public class AuaActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

	Jua.init();
    }

    @Override
    public void onDestroy()
    {
	Jua.free();
	super.onDestroy();
    }
}
