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

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "XPLMProcessing.h"
#include "XPLMDataAccess.h"
#include "XPLMUtilities.h"
#include "XPLMGraphics.h"

using namespace std;
//using std::cerr;
//using std::cout;
//using std::endl;

//header files for socket programming

#include <WinSock.h>
#include <io.h>
#include <stdlib.h>
#include <iostream>
/*
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>	
*/
static const int endianTest = 1;
#define isLittleEndian (*((char *) &endianTest ) != 0)

// Routine to correct the endiness

// Double version
static void htond (double &x)
{
    if ( isLittleEndian ) {
        int    *Double_Overlay;
        int     Holding_Buffer;

        Double_Overlay = (int *) &x;
        Holding_Buffer = Double_Overlay [0];

        Double_Overlay [0] = htonl (Double_Overlay [1]);
        Double_Overlay [1] = htonl (Holding_Buffer);
    } else {
        return;
    }
}

// Float version
static void htonf (float &x)
{
    if ( isLittleEndian ) {
        int    *Float_Overlay;
        int     Holding_Buffer;

        Float_Overlay = (int *) &x;
        Holding_Buffer = Float_Overlay [0];

        Float_Overlay [0] = htonl (Holding_Buffer);
    } else {
        return;
    }
}





//X-Plane format for position data

#pragma pack(push,2)
class XPNetFDM{
public:
    int p; // this is the plane you wish to control.. 0 for your plane, but you can enter up to 9 here
	double lat_lon_ele[3];
	float psi_the_phi[3];
	float gear_flap_vect[3];
};
#pragma pack(pop)




XPNetFDM fdm;



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
XPLMDataRef		gPhyOFF;
XPLMDataRef		gHUDON;

#if APL && __MACH__
int ConvertPath(const char * inPath, char * outPath, int outPathMaxLen);
#endif

int sckt;
struct sockaddr_in scktName;

//connection to JSBSim Socket
void JSBSimUDPSocket(int port)
{
  int size = 0;
  bool connected = false;
  unsigned long NoBlock = true;

  #if defined(_MSC_VER) || defined(__MINGW32__)
    WSADATA wsaData;
    int wsaReturnCode;
    wsaReturnCode = WSAStartup(MAKEWORD(1,1), &wsaData);
    if (wsaReturnCode == 0) cout << "Winsock DLL loaded ..." << endl;
    else cerr << "Winsock DLL not initialized ..." << endl;
  #endif

  sckt = socket(AF_INET, SOCK_DGRAM, 0);

  if (sckt >= 0) {  // successful
    memset(&scktName, 0, sizeof(struct sockaddr_in));
    scktName.sin_family = AF_INET;
    scktName.sin_port = htons(port);
    scktName.sin_addr.s_addr = htonl(INADDR_ANY);
    int len = sizeof(struct sockaddr_in);
    if (bind(sckt, (struct sockaddr*)&scktName, len) == 0) {   // successful
      cout << "Successfully bound to socket for input on port " << port << endl;
      connected = true;
    } else {                // unsuccessful
      cout << "Could not bind to socket for input ..." << endl;
    }
  } else {          // unsuccessful
    cout << "Could not create socket for FDM input, error = " << endl;
  }

}

//Recieve from JSBSim
int JSBSimUDPReceive(char *buf)
{

  struct sockaddr_in si_other;
  int len = sizeof(struct sockaddr_in);
  int num_chars=0;
  int total_chars = 0;
  unsigned long NoBlock = true;
  

  if (sckt > 0) {
    num_chars = recvfrom(sckt, buf, 1024, 0, (sockaddr *)&si_other, &len);
	if( num_chars == 0  ) {
      		cout<<"error transmission";
      		return 0;
   	}
	//cout<<"no of chars recieve"<<num_chars<<endl;	
	
      	

#if defined(_MSC_VER)
    // when nothing received and the error isn't "would block"
    // then assume that the client has closed the socket.
    if (num_chars == 0) {
        DWORD err = WSAGetLastError ();
        if (err != WSAEWOULDBLOCK) {
            printf ("Socket Closed. back to listening\n");
            closesocket (sckt);
            sckt = -1;
        }
    }
#endif
  }

  return num_chars;
}




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
	
	
	JSBSimUDPSocket(1999);	//fixed port to listen	
	
	strcpy(outName, "JSBSim Plugin");
	strcpy(outSig, "xplanesdk.plugin.jsbsim");
	strcpy(outDesc, "Plugin that integrate X-Plane with JSBSim at port 1999");

	
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
	gPhyOFF	= XPLMFindDataRef("sim/operation/override/override_planepath");
	//gHUDON = XPLMFindDataRef("sim/cockpit/electrical/HUD_on");
	
	//turning off the physics engine
	int IntVals[8]; 
	memset(IntVals, 0, sizeof(IntVals)); 
	IntVals[0] = 1; 
	XPLMSetDatavi(gPhyOFF, IntVals, 0, 8); 	
	//XPLMSetDatai(gHUDON, 1);

	/* Register our callback for once a second.  Positive intervals
	 * are in seconds, negative are the negative of sim frames.  Zero
	 * registers but does not schedule a callback for time. */
	XPLMRegisterFlightLoopCallback(		
			MyFlightLoopCallback,	/* Callback */
			-1,					/* Interval */
			NULL);					/* refcon not used. */
			
	return 1;
}

PLUGIN_API void	XPluginStop(void)
{
	/* Unregister the callback */
	XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);
	
	/* Close the file */
	//fclose(fptr);
}

PLUGIN_API void XPluginDisable(void)
{
	/* Flush the file when we are disabled.  This is convenient; you 
	 * can disable the plugin and then look at the output on disk. */
	//fflush(fptr);
}

PLUGIN_API int XPluginEnable(void)
{
	return 1;
}

PLUGIN_API void XPluginReceiveMessage(
					XPLMPluginID	inFromWho,
					long			inMessage,
					void *			inParam)
{
}


float	MyFlightLoopCallback(
                                   float                inElapsedSinceLastCall,    
                                   float                inElapsedTimeSinceLastFlightLoop,    
                                   int                  inCounter,    
                                   void *               inRefcon)
{
	

	char buff[57];
	int size=JSBSimUDPReceive((char *)buff);
	
	if (size > 0){
		memcpy((char *)&fdm,(char *)&buff[5],52);
		double x,y,z;
	
		htond(fdm.lat_lon_ele[0]);
		htond(fdm.lat_lon_ele[1]);
		htond(fdm.lat_lon_ele[2]);
		htonf(fdm.psi_the_phi[0]);
		htonf(fdm.psi_the_phi[1]);
		htonf(fdm.psi_the_phi[2]);
		htonf(fdm.gear_flap_vect[0]);
		htonf(fdm.gear_flap_vect[1]);
		htonf(fdm.gear_flap_vect[2]);

		//copy world coordinates to local coordinates
		XPLMWorldToLocal(fdm.lat_lon_ele[0], fdm.lat_lon_ele[1], fdm.lat_lon_ele[2] , &x, &y, &z);

		XPLMSetDatad(gPlanelocal_x, x);
		XPLMSetDatad(gPlanelocal_y, y);
		XPLMSetDatad(gPlanelocal_z, z);
		XPLMSetDataf(gPlanelocal_psi, fdm.psi_the_phi[0]*180/3.141);
		XPLMSetDataf(gPlanelocal_theta, fdm.psi_the_phi[1]*180/3.141);
		XPLMSetDataf(gPlanelocal_phi, fdm.psi_the_phi[2]*180/3.141);
		XPLMSetDataf(gPlanelocal_theta, fdm.psi_the_phi[1]*180/3.141);
		XPLMSetDataf(gPlanelocal_phi, fdm.psi_the_phi[2]*180/3.141);
		
		//XPLMSetDataf(gPlanelocal_theta, fdm.gear_flap_vect[1]);
		//XPLMSetDataf(gPlanelocal_phi, fdm.gear_flap_vect[2]);
		
	}
		



	return -1.0;
}                                   


