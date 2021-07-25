#include <Windows.h>
//#include <sstream>  // needed for printfs only

#include "SimConnect.h"

#include "MSFS-SimConnect-Data.h"
#include "MSFS-SimConnect-DataFormat.h"


bool prepare_data_requests(HANDLE* hSimConnect) {
	/// <summary>
	/// intentionally returning bool to hide inner implementation from upstream callers
	/// </summary>
	/// <param name="hSimConnect"></param>
	/// <returns>bool</returns>
	bool success = false;
	HRESULT hr;
	if (hSimConnect) {
		hr = SimConnect_Open(hSimConnect, "MSFS-SimConnect-CLI-bauman", NULL, NULL, NULL, NULL);
		if (SUCCEEDED(hr)) {
			// set up the definitions for the data frames.  Intentionally seperated the data called per frame and the data called per second
			hr |= register_per_second_data(hSimConnect, DEFINITION_ID_AP);
			hr |= register_per_frame_data(hSimConnect, DEFINITION_ID_RL);

			// send the request for the data about the current user at the appropriate frequency
			hr |= SimConnect_RequestDataOnSimObject(*hSimConnect, REQUEST_AP_SETTINGS, DEFINITION_ID_AP, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SECOND);
			hr |= SimConnect_RequestDataOnSimObject(*hSimConnect, REQUEST_RL_SETTINGS, DEFINITION_ID_RL, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME, 0);
		}
	}
	success = SUCCEEDED(hr);
	return success;
}

void data_collection_loop(HANDLE* hSimConnect) {
    /// <summary>
    /// This function wraps the !THREAD UNSAFE! data collection loop
    /// 
    /// the idea is to spend one thread doing the collection as easy as possible 
    /// and get the data copied off to a worker thread as fast as possible
    /// this thread probably shouldn't be doing anythign beyond 
    ///     1. pulling new data from SimConnect
    ///     2. determining which struct it belongs in
    ///     3. casting the data blob into the struct
    ///     4. copying the data contents into another memory area
    ///     5. sending the data to a worker thread to do something. 
    /// </summary>
    /// <param name="hSimConnect"></param>
    
    HRESULT hr;
    SIMCONNECT_RECV* pData = NULL;
    DWORD cbData = 0;
    bool bRequestProcessed = false;
    int SelectedAltitude = 0;
    SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = NULL;
    DataRefs* pDataRefs = NULL;
    FrameData* pFrameDataRefs = NULL;

    bRequestProcessed = false;
    while (!bRequestProcessed)
    {
        hr = SimConnect_GetNextDispatch(*hSimConnect, &pData, &cbData);
        if (SUCCEEDED(hr))
        {
            switch (pData->dwID) {
            case SIMCONNECT_RECV_ID_SIMOBJECT_DATA:
            {
                pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
                switch (pObjData->dwDefineID) {
                case DEFINITION_ID_RL: {
                    pFrameDataRefs = (FrameData*)&pObjData->dwData;  // this is wrong for now
                    pFrameDataRefs->aileron;
                    break;
                }
                case DEFINITION_ID_AP: {
                    pDataRefs = (DataRefs*)&pObjData->dwData;
                    pDataRefs->altitude.aboveSea;
                    //printf("\rAltitude: %6.3f ", pDataRefs->altitude.aboveSea);
                    //printf("  Above: %6.3f ", pDataRefs->above );
                    //printf("  Speed: %6.3f ", pDataRefs->speed.knots);
                    //printf("  Indi: %6.3f ", pDataRefs->indicated);
                    //printf("  mach: %6.3f ", pDataRefs->mach);
                    //printf("  vert: %6.3f ", pDataRefs->vertical);
                    //printf("  head: %2.6f ", pDataRefs->heading * 57.2958);

                    //printf("  Pitch: %6.6f ", pDataRefs->attitude.pitch * 57.2958);
                    //printf("  Bank: %6.6f ", pDataRefs->attitude.bank * 57.2958);
                    //printf("  Lon: %6.6f ", pDataRefs->lon * 57.2958);
                    //printf("  lat: %6.6f ", pDataRefs->lat * 57.2958);
                    //printf("  fuel: %6.6f ", pDataRefs->fuel.fuelTotal);
                    //printf("  extended: %3.3f ", pDataRefs->aircraft.gear.extended * 100 * 100);
                    //printf("   engines: %2.1f ", pDataRefs->aircraft.numEngines);
                    //printf("   landing %s", pDataRefs->aircraft.gear.down ? "true" : "false");
                    //printf("   ground %s", pDataRefs->altitude.onGround ? "true" : "false");
                    // placeholder for sending notifications to the screen
                    //if (!displayed) {
                    //    displayed = true;
                    //    SimConnect_Text(hSimConnect, SIMCONNECT_TEXT_TYPE_PRINT_BLACK, 0, EVENT_TEXT_1, sizeof(Message1), (void*)Message1);
                    //}
                    break;
                }
                default: {
                    break;
                }
                }
                break;
            }
            case SIMCONNECT_RECV_ID_EVENT:
            {
                pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
                switch (pObjData->dwObjectID) {
                case EVENT_TEXT_1: {
                    break;
                }
                default:
                    break;
                }
                break;
            }
            case SIMCONNECT_RECV_ID_QUIT:
            {
                bRequestProcessed = true;
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

    // Close
    hr = SimConnect_Close(*hSimConnect);
}