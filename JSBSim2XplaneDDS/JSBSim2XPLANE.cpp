/*
 * TimedProcessing.c
 * 
 * This example plugin demonstrates how to use the timed processing callbacks
 * to continuously record sim data to disk.
 * 
 * This technique can be used to record data to disk or to the network.  Unlike
 * UDP data output, we can increase our frequency to capture data every single
 * sim frame.  (This example records once per second.)
 * 
 * Use the timed processing APIs to do any periodic or asynchronous action in
 * your plugin.
 * 
 */

#if APL
#if defined(__MACH__)
#include <Carbon/Carbon.h>
#endif
#endif

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "XPLMProcessing.h"
#include "XPLMDataAccess.h"
#include "XPLMUtilities.h"
#include "XPLMGraphics.h"
#include "XPLMPlugin.h"
#include "XPStandardWidgets.h"
#include "XPWidgets.h"
#include "XPWidgetDefs.h"
#include "XPUIGraphics.h"
#include "XPWidgetUtils.h"

#include "XPLMMenus.h"
#include "XPLMUtilities.h"

#include "JSBSim.h"
#include "DDSInterface.h"
JSBSim::DDSInterface dds;


int MenuItem1;
XPLMMenuID	id;

int port=2000;

XPWidgetID TestWidgetsWidget, TestWidgetsWindow;
XPWidgetID PopupInputTextEdit;

using namespace std;
using std::cout;
using std::endl;


/* Data refs we will record. */
XPLMDataRef		gPlanelocal_x;
XPLMDataRef		gPlanelocal_y;
XPLMDataRef		gPlanelocal_z;
XPLMDataRef		gPlanelocal_theta;
XPLMDataRef		gPlanelocal_phi;
XPLMDataRef		gPlanelocal_psi;
XPLMDataRef		gFlightModel_gear;
XPLMDataRef		gFlightModel_flap;
XPLMDataRef		gFlightModel_thrust;
XPLMDataRef		gFlight_time;
XPLMDataRef		gFlight_date;
XPLMDataRef		gFlightModel_speed;
XPLMDataRef		gFlight_zulutime;
XPLMDataRef		gPhyOFF;
XPLMDataRef		gHUDON;

#if APL && __MACH__
int ConvertPath(const char * inPath, char * outPath, int outPathMaxLen);
#endif

void DisableNativeFDM();
void  JSBSimMenuHandler (void *, void *);
int	JSBSimMenuEventHandler(
						XPWidgetMessage			inMessage,
						XPWidgetID				inWidget,
						long					inParam1,
						long					inParam2);



float	MyFlightLoopCallback(
                                   float                inElapsedSinceLastCall,    
                                   float                inElapsedTimeSinceLastFlightLoop,    
                                   int                  inCounter,    
                                   void *               inRefcon);    


PLUGIN_API int XPluginStart(
						char *		outName,
						char *		outSig,
						char *		outDesc)
{	
	
	int item;


	strcpy(outName, "JSBSim Plugin");
	strcpy(outSig, "xplanesdk.plugin.jsbsim");
	strcpy(outDesc, "Plugin that integrate X-Plane with JSBSim");


	item = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "JSBSim Plugin", NULL, 1);

	id = XPLMCreateMenu("JSBSim Plugin", XPLMFindPluginsMenu(), item, JSBSimMenuHandler, NULL);
	XPLMAppendMenuItem(id, "Configure Socket", (void *)"socket", 1);

	// Used by widget to make sure only one widgets instance created
	MenuItem1 = 0;

	/* Find the data refs we want to record. */
	gPlanelocal_x = XPLMFindDataRef("sim/flightmodel/position/local_x");
	gPlanelocal_y = XPLMFindDataRef("sim/flightmodel/position/local_y");
	gPlanelocal_z = XPLMFindDataRef("sim/flightmodel/position/local_z");
	gPlanelocal_theta = XPLMFindDataRef("sim/flightmodel/position/theta");
	gPlanelocal_phi = XPLMFindDataRef("sim/flightmodel/position/phi");
	gPlanelocal_psi = XPLMFindDataRef("sim/flightmodel/position/psi");
	gFlightModel_gear=XPLMFindDataRef("sim/flightmodel2/gear/deploy_ratio");
	gFlightModel_flap=XPLMFindDataRef("sim/flightmodel2/controls/flap_handle_deploy_ratio");
	gFlightModel_thrust=XPLMFindDataRef("sim/flightmodel2/controls/thrust_vector_ratio");
	gFlight_time = XPLMFindDataRef("sim/time/local_time_sec");
	gFlight_zulutime = XPLMFindDataRef("sim/time/zulu_time_sec");
	gFlight_date = XPLMFindDataRef("sim/time/local_date_days");
	gFlightModel_speed = XPLMFindDataRef("sim/flightmodel/position/indicated_airspeed");
	gPhyOFF	= XPLMFindDataRef("sim/operation/override/override_planepath");
	

	/* Register our callback for once a second.  Positive intervals
	 * are in seconds, negative are the negative of sim frames.  Zero
	 * registers but does not schedule a callback for time. */
	XPLMRegisterFlightLoopCallback(		
			MyFlightLoopCallback,	/* Callback */
			-1,					/* Interval */
			NULL);					/* refcon not used. */
			
	DisableNativeFDM();
	return 1;
}

PLUGIN_API void	XPluginStop(void)
{
	/* Unregister the callback */
	//XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);
	
	/* Close the file */
	//fclose(fptr);

	/* Unregister the callback */
	int IntVals[8]; 
	memset(IntVals, 0, sizeof(IntVals)); 
	IntVals[0] = 0; 
	XPLMSetDatavi(gPhyOFF, IntVals, 0, 8); 
	XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);
	
	XPLMDestroyMenu(id);
	if (MenuItem1 == 1)
	{
		XPDestroyWidget(TestWidgetsWidget, 1);
		MenuItem1 = 0;
	}

	
	/* Close the file */
	//fclose(fptr);

}

PLUGIN_API void XPluginDisable(void)
{
	/* Flush the file when we are disabled.  This is convenient; you 
	 * can disable the plugin and then look at the output on disk. */
	//fflush(fptr);

	/* Flush the file when we are disabled.  This is convenient; you 
	 * can disable the plugin and then look at the output on disk. */
	//fflush(fptr);
	int IntVals[8]; 
	memset(IntVals, 0, sizeof(IntVals)); 
	IntVals[0] = 0; 
	XPLMSetDatavi(gPhyOFF, IntVals, 0, 8);
	XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);

}

PLUGIN_API int XPluginEnable(void)
{
	//int IntVals[8]; 
	//memset(IntVals, 0, sizeof(IntVals)); 
	//IntVals[0] = 1; 	
	//XPLMSetDatavi(gPhyOFF, IntVals, 0, 8);
	//XPLMRegisterFlightLoopCallback(		
	//		MyFlightLoopCallback,	/* Callback */
	//		-1,					/* Interval */
	//		NULL);					/* refcon not used. */
	return 1;

}

PLUGIN_API void XPluginReceiveMessage(
					XPLMPluginID	inFromWho,
					long			inMessage,
					void *			inParam)
{
}

void DisableNativeFDM(){

	int IntVals[8]; 
	memset(IntVals, 0, sizeof(IntVals)); 
	IntVals[0] = 1; 	
	XPLMSetDatavi(gPhyOFF, IntVals, 0, 8);
}

void CreateTestWidgets(int x, int y, int w, int h)
{
	int x2 = x + w;
	int y2 = y - h;

	TestWidgetsWidget = XPCreateWidget(x, y, x2, y2,
					1,	// Visible
					"JSBSim Plugin (configure socket)",	// desc
					1,		// root
					NULL,	// no container
					xpWidgetClass_MainWindow);

	XPSetWidgetProperty(TestWidgetsWidget, xpProperty_MainWindowHasCloseBoxes, 1);

	TestWidgetsWindow = XPCreateWidget(x+5, y-20, x2-5, y2+5,
						1,	// Visible
						"Port",	// desc
						0,		// root
						TestWidgetsWidget,
						xpWidgetClass_SubWindow);

	XPSetWidgetProperty(TestWidgetsWindow, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);


	PopupInputTextEdit = XPCreateWidget(x+80, y-30, x2-10, y-132,
								1, "2000", 0, TestWidgetsWidget,
									xpWidgetClass_TextField);

	XPSetWidgetProperty(PopupInputTextEdit, xpProperty_TextFieldType, xpTextEntryField);
}

void  JSBSimMenuHandler(void * mRef, void * iRef)
{
	if (!strcmp((char *) iRef, "socket"))
	{
		if (MenuItem1 == 0)
		{
			CreateTestWidgets(300, 400, 300, 100);
			MenuItem1 = 1;
		}
		else
			if(!XPIsWidgetVisible(TestWidgetsWidget))
				XPShowWidget(TestWidgetsWidget);
	}

	XPAddWidgetCallback(TestWidgetsWidget, JSBSimMenuEventHandler);
}		


// Handle any widget messages
int	JSBSimMenuEventHandler(
						XPWidgetMessage			inMessage,
						XPWidgetID				inWidget,
						long					inParam1,
						long					inParam2)
{
	char Buffer[10];

	// Close button pressed, only hide the widget, rather than destropying it.
	if (inMessage == xpMessage_CloseButtonPushed)
	{
		if (MenuItem1 == 1)
		{
			XPGetWidgetDescriptor(PopupInputTextEdit, Buffer, sizeof(Buffer));
//			port = atoi(Buffer);
//			JSBSimUDPSocket(port);
			XPHideWidget(TestWidgetsWidget);
		}
		return 1;
	}
}




float	MyFlightLoopCallback(
                                   float                inElapsedSinceLastCall,    
                                   float                inElapsedTimeSinceLastFlightLoop,    
                                   int                  inCounter,    
                                   void *               inRefcon)
{
	
	double x,y,z;
	double radtodeg = 180/3.1412;
	JSBSim::fdmdata jsbsim_fdm;
	if(dds.Run(jsbsim_fdm)){
		XPLMWorldToLocal(jsbsim_fdm.Latitude, jsbsim_fdm.Longitude, jsbsim_fdm.AltitudeAboveSeaLevel_ft*0.3048 , &x, &y, &z);
		XPLMSetDatad(gPlanelocal_x, x);
		XPLMSetDatad(gPlanelocal_y, y);
		XPLMSetDatad(gPlanelocal_z, z);
		XPLMSetDataf(gPlanelocal_psi, jsbsim_fdm.Heading_deg);
		XPLMSetDataf(gPlanelocal_theta, jsbsim_fdm.Pitch_deg);
		XPLMSetDataf(gPlanelocal_phi, jsbsim_fdm.Roll_deg);
		XPLMSetDataf(gFlight_zulutime, jsbsim_fdm.SimTime);
	}

	return -1.0;
}                                   


