package com.example.media.controller;

import android.os.Bundle;
import android.app.Activity;
import android.sax.TextElementListener;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.SlidingDrawer;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.*;

import com.example.media.controller.R;

public class MainActivity extends Activity {
	
	private Socket socket;
	private OutputStreamWriter out;
	private int progressBarNav = 0;
	private int progressBarVol = 0;
	private String ip;
	
	public void setIp(String ip) {
		this.ip = ip;
	}
	

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        SeekBar navBar = ( SeekBar ) findViewById( R.id.navBar );
        SeekBar volBar = ( SeekBar ) findViewById( R.id.volBar );
        
        //navBar.setProgress( navBar.getMax() / 2 );
        volBar.setProgress( volBar.getMax() / 2 );
        progressBarVol = volBar.getProgress();
        
        /***** NAV BAR LISTENER ****/
        
        navBar.setOnSeekBarChangeListener( new OnSeekBarChangeListener() {
        	
        	TextView t = ( TextView ) findViewById( R.id.t_status );
			
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
				progressBarNav = seekBar.getProgress();
			}
			
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			public void onProgressChanged(SeekBar seekBar, int progress,
					boolean fromUser) {
				// TODO Auto-generated method stub
				
				if( progressBarNav < progress )
				{
					if( socket != null )
					{
						try {
						
							
							out.write("Forward");
							out.flush();
							
							t.setText("Forward: OK");
							
							//Thread.sleep( 300 );
							
						} catch (IOException e) {
							// TODO Auto-generated catch block
							
							System.out.println("IO Exception.");
							
							t.setText("Forward: FAIL - IO Exception");
							
							e.printStackTrace();
						}
					}
				}
				else if( progressBarNav > progress )
				{
					if( socket != null )
					{
						try {
							
							out.write("Rewind");
							out.flush();
							
							t.setText("Rewind: OK");
							
							//Thread.sleep( 300 );
							
						} catch (IOException e) {
							// TODO Auto-generated catch block
							
							System.out.println("IO Exception.");
							
							t.setText("Rewind: FAIL - IO Exception");
							
							e.printStackTrace();
						}
					}
				}
				
			}
		});
        
        
        /***** VOL BAR LISTENER ****/
        
        volBar.setOnSeekBarChangeListener( new OnSeekBarChangeListener() {
        	
        	TextView t = ( TextView ) findViewById( R.id.t_status );
			
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
				progressBarVol = seekBar.getProgress();
			}
			
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			public void onProgressChanged(SeekBar seekBar, int progress,
					boolean fromUser) {
				// TODO Auto-generated method stub
				
				if( progressBarVol < progress )
				{
					if( socket != null )
					{
						try {
							
							out.write("VolumeUp");
							out.flush();
							
							t.setText("VolumeUp: OK");
							
							//Thread.sleep( 300 );
							
						} catch (IOException e) {
							// TODO Auto-generated catch block
							
							System.out.println("IO Exception.");
							
							t.setText("VolumeUp: FAIL - IO Exception");
							
							e.printStackTrace();
						}
					}
				}
				else if( progressBarVol > progress )
				{
					if( socket != null )
					{
						try {
							
							out.write("VolumeDown");
							out.flush();
							
							t.setText("VolumeDown: OK");
							
							//Thread.sleep( 300 );
							
						} catch (IOException e) {
							// TODO Auto-generated catch block
							
							System.out.println("IO Exception.");
							
							t.setText("VolumeDown: FAIL - IO Exception");
							
							e.printStackTrace();
						}
					}
				}
				
			}
		});
        
    }
    
    public void onClickConnect( View v )
    {
    	TextView t = ( TextView ) findViewById( R.id.t_status );
    	
    	try {
    		
    			if( socket == null )
    			{
    				socket = new Socket( ip , 1337 );
    				
    				out = new OutputStreamWriter( socket.getOutputStream() );
    				
    				
    				if( socket.isConnected() )
    				{
    					t.setText("Connection: OK");
    					
    				}
    				else
    				{
    					t.setText("Connection: FAIL");
    				}
    			}
    			else
    			{
    				if( socket.isConnected() )
    				{
    					out.write("Disconnect");
    					out.flush();
    					
    					out.close();
    					socket.close();
    					
    					t.setText("Disconnect: OK");
    				}
    			}
			
				
			} catch (UnknownHostException e) {
				// TODO Auto-generated catch block
				System.out.println("Cannot find host.");
				
				t.setText("Connection: FAIL - Unknown Host");
				
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println("IO Exception.");
				
				t.setText("Connection: FAIL - IO Exception");
				
				e.printStackTrace();
			}
    }
    
    public void onClickPlay( View v )
    {
    	TextView t = ( TextView ) findViewById( R.id.t_status );
    	
    	try {
    		
			out.write("Play");
			out.flush();
			
			if( t.getText().equals("Play: OK") )
			{
				t.setText("Pause: OK");
			}
			else
			{
				t.setText("Play: OK");
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			
			if( t.getText().toString().contains("Play") )
			{
				t.setText("Pause: FAIL - IO Exception");
			}
			else
			{
				t.setText("Play: FAIL - IO Exception");
			}
			
			
			e.printStackTrace();
		}
    	
    }
    
    public void onClickTime( View v )
    {
		TextView t = ( TextView ) findViewById( R.id.t_status );
    	
    	try {
    		
			out.write("Time");
			out.flush();
			
			t.setText("Time: OK");
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			
			t.setText("Time: FAIL - IO Exception");
		
			e.printStackTrace();
		}
    }

    public void onClickIp( View v )
    {
    	EditText te = ( EditText )findViewById( R.id.te_ip );
    	TextView tv = ( TextView )findViewById( R.id.t_status );
    	
    	setIp( te.getText().toString() );
    	
    	
    	tv.setText("Server IP: " + ip );
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}
