#include <Windows.h>
#include "SimConnect.h"
#include "MSFS-SimConnect-DataFormat.h"


HRESULT register_per_frame_data(HANDLE* hSimConnect, SIMCONNECT_DATA_DEFINITION_ID DEFINITION_ID) {
    /// <summary>
    /// The definitions in this function must match EXACTLY with the data struct FrameData defined in DataFormat.h
    /// 
    /// SimConnect will add these definitions and types as a single data blob that we'll overlay the FrameData struct onto.
    /// 
    /// Any changes to adding definitions must include an update to the DataRefs struct or embedded members
    /// </summary>
    /// <param name="hSimConnect">main connection handle to MSFS through SimConnect</param>
    /// <param name="DEFINITION_ID">
    ///     This is any unique number that the runtime loop will hand back to us so we know which data format it is
    /// </param>
    /// <returns>HRESULT (either S_OK or S_FAIL)</returns>
    HRESULT hr = SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AILERON POSITION", "Position");
    return hr;
}

HRESULT register_per_second_data(HANDLE* hSimConnect, SIMCONNECT_DATA_DEFINITION_ID DEFINITION_ID) {
    /// <summary>
    /// The definitions in this function must match EXACTLY with the data struct DataRefs defined in DataFormat.h
    /// 
    /// SimConnect will add these definitions and types as a single data blob that we'll overlay the DataRefs struct onto.
    /// 
    /// Any changes to adding definitions must include an update to the DataRefs struct or embedded members
    /// 
    /// </summary>
    /// <param name="hSimConnect">main connection handle to MSFS through SimConnect</param>
    /// <param name="DEFINITION_ID">
    ///     This is any unique number that the runtime loop will hand back to us so we know which data format it is
    /// </param>
    /// <returns>HRESULT (either S_OK or S_FAIL)</returns>
    
    HRESULT hr = SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "SIMULATION RATE", "Number");

    // Environment
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT DENSITY", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT TEMPERATURE", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT PRESSURE", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT WIND VELOCITY", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT WIND DIRECTION", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT WIND X", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT WIND Y", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AMBIENT WIND Z", "Number");

    // Alts
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "SIM ON GROUND", "BOOL", SIMCONNECT_DATATYPE_INT64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE ALTITUDE", "Feet");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE ALT ABOVE GROUND", "Feet");

    //Speed
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "GROUND VELOCITY", "Knots");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AIRSPEED TRUE", "Knots");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AIRSPEED INDICATED", "Knots");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "AIRSPEED MACH", "Mach");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "VERTICAL SPEED", "Feet per second");

    // Attitude
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE PITCH DEGREES", "Radians");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE BANK DEGREES", "Radians");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ROTATION VELOCITY BODY X", "Radians per second");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE HEADING DEGREES TRUE", "Radians");

    // Geo
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE LATITUDE", "Radians");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "PLANE LONGITUDE", "Radians");

    // Fuel
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "GENERAL ENG FUEL USED SINCE START", "Pounds");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FUEL TOTAL QUANTITY", "Gallons");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FUEL TOTAL QUANTITY WEIGHT", "Pounds");

    // LocalClock
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LOCAL YEAR", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LOCAL MONTH OF YEAR", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LOCAL DAY OF MONTH", "Number");


    // aircraft
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "TOTAL WEIGHT", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "MAX GROSS WEIGHT", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "EMPTY WEIGHT", "Number");


    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ENGINE TYPE", "Enum", SIMCONNECT_DATATYPE_INT32);
    /*0 = Piston 1 = Jet 2 = None 3 = Helo(Bell) turbine 4 = Unsupported 5 = Turboprop*/
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "NUMBER OF ENGINES", "Number", SIMCONNECT_DATATYPE_INT32);

    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "GEAR TOTAL PCT EXTENDED", "Number");
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "GEAR DAMAGE BY SPEED", "Bool", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "IS GEAR RETRACTABLE", "Bool", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "IS GEAR SKIS", "Bool", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "IS GEAR FLOATS", "Bool", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "IS GEAR SKIDS", "Bool", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "IS GEAR WHEELS", "Bool", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "GEAR HANDLE POSITION", "Bool", SIMCONNECT_DATATYPE_INT32);



    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FLAPS AVAILABLE", "Bool", SIMCONNECT_DATATYPE_INT64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FLAPS NUM HANDLE POSITIONS", "Number", SIMCONNECT_DATATYPE_INT64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FLAPS HANDLE INDEX", "Number", SIMCONNECT_DATATYPE_INT64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FLAP DAMAGE BY SPEED", "Bool", SIMCONNECT_DATATYPE_INT64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "FLAP SPEED EXCEEDED", "Bool", SIMCONNECT_DATATYPE_INT64);



    // Lights
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT TAXI ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT STROBE ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT PANEL ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT RECOGNITION ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT WING ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT LOGO ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT CABIN ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT HEAD ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT BRAKE ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT NAV ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT BEACON ON", "BOOL", SIMCONNECT_DATATYPE_INT32);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "LIGHT LANDING ON", "BOOL", SIMCONNECT_DATATYPE_INT32);



    // aircraft data strings
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ATC TYPE", NULL, SIMCONNECT_DATATYPE_STRING64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ATC MODEL", NULL, SIMCONNECT_DATATYPE_STRING64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ATC AIRLINE", NULL, SIMCONNECT_DATATYPE_STRING64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ATC ID", NULL, SIMCONNECT_DATATYPE_STRING64);
    hr |= SimConnect_AddToDataDefinition(*hSimConnect, DEFINITION_ID, "ATC FLIGHT NUMBER", NULL, SIMCONNECT_DATATYPE_STRING8);
    return hr;
}

