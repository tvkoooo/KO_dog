package org.mm.flake;

import org.mm.core.mm_logger;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.FrameLayout;

public class mm_flake_activity_impl extends Activity 
{
	private static final String TAG = mm_flake_activity_impl.class.getSimpleName();
	
	public mm_flake_frame_layout d_flake_frame_layout = null;
	
	@Override
	public void onCreate(final Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		
		Log.i(TAG, TAG + " onCreate event begin.");
		
    	// FrameLayout
		FrameLayout.LayoutParams framelayout_params = new FrameLayout.LayoutParams(
				FrameLayout.LayoutParams.MATCH_PARENT, 
				FrameLayout.LayoutParams.MATCH_PARENT);

        this.d_flake_frame_layout = new mm_flake_frame_layout(this);
        this.d_flake_frame_layout.setLayoutParams(framelayout_params);
        this.d_flake_frame_layout.load_library("Plugin_ParticleUniverse");
        this.d_flake_frame_layout.load_library("mm_net");
		this.d_flake_frame_layout.assign_native_lib("KO_dog");
		this.d_flake_frame_layout.set_main_surface_canvas_size(1920, 1080);
		this.d_flake_frame_layout.set_logical_frequency(20.0f);
		this.d_flake_frame_layout.set_display_frequency(60.0f);
		this.d_flake_frame_layout.assign_logger_level(mm_logger.MM_LOG_INFO);
		this.d_flake_frame_layout.finish_launching();
		this.d_flake_frame_layout.start();
		
		this.setContentView(this.d_flake_frame_layout);
		Log.i(TAG, TAG + " onCreate event end.");
		Log.i(TAG, TAG + " init succeed.");
	}
	
	@Override
	protected void onStart() 
	{
		super.onStart();
		Log.i(TAG, TAG + " onStart event.");
	}
	
	@Override
	protected void onResume() 
	{
		super.onResume();
		Log.i(TAG, TAG + " onResume event.");
		this.d_flake_frame_layout.enter_foreground();
	}

	@Override
	protected void onPause() 
	{
		super.onPause();
		Log.i(TAG, TAG + " onPause event.");
		this.d_flake_frame_layout.enter_background();
	}
	
	@Override
	protected void onStop() 
	{
		super.onStop();
		Log.i(TAG, TAG + " onStop event.");
	}
	
	@Override
	protected void onDestroy() 
	{
		Log.i(TAG, TAG + " onDestroy event.");
		
		this.d_flake_frame_layout.shutdown();
		this.d_flake_frame_layout.join();
		this.d_flake_frame_layout.before_terminate();
		
		super.onDestroy();
		Log.i(TAG, TAG + " destroy succeed.");
	}
};
