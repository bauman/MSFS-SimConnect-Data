
#include <Windows.h>
#include "MSFS-SimConnect-Data.h"
#include "MSFS-SimConnect-DataFormat.h"

// Don't forget to drop simconnect.dll into the run directory!
// file:///C:/MSFS%20SDK/Documentation/html/index.htm#t=Programming_Tools%2FSimConnect%2FSimConnect_SDK.htm&rhsearch=visual%20studio&rhhlterm=visual%20studio
// file:///C:/MSFS%20SDK/Documentation/html/index.htm#t=Programming_Tools%2FSimConnect%2FSimConnect_API_Reference.htm
// file:///C:/MSFS%20SDK/Documentation/html/index.htm#t=Programming_Tools%2FSimConnect%2FStatus%2FStatus_Of_Simulation_Variables.htm



/// placeholder content to display data on the MSFS HUD
//bool displayed = false;
//static const char Empty1[] = "";
//static const char Message1[] = "Example Multi line \n\n     Message Data for feature used later";



HANDLE hSimConnect = NULL;


int main() {

    bool prepped = prepare_data_requests(&hSimConnect);
    if (prepped) {
        data_collection_loop(&hSimConnect);
    }
    return 0;
}