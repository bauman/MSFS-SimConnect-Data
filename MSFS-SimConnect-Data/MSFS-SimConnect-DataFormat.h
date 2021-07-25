// MSFS-SimConnect-DataFormat.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "SimConnect.h"

// TODO: Reference additional headers your program requires here.
struct FrameData {
    double aileron;
};


struct Alts {
    DWORD onGround;
    double aboveSea;
    double aboveGround;
};

struct Speed {
    double ground;
    double knots;
    double indicated;
    double mach;
    double vertical;
};

struct Attitude {
    double pitch;
    double bank;
    double bankRate;
    double heading;
};

struct Geo {
    double lat;
    double lon;
};

struct Fuel {
    double fuelUsed;
    double fuelTotal;
    double fuelTotalWeight;
};
struct Lights {
    DWORD32 taxi;
    DWORD32 strobe;
    DWORD32 panel;
    DWORD32 recognition;
    DWORD32 wing;
    DWORD32 logo;
    DWORD32 cabin;
    DWORD32 head;
    DWORD32 brake;
    DWORD32 nav;
    DWORD32 beacon;
    DWORD32 landing;
};

struct Sim {
    double rate;
};

struct Wind {
    double velocity;
    double direction;
    double x;
    double y;
    double z;
};
struct Env {
    double density;
    double temperature;
    double pressure;
    struct Wind ambient_wind;
};

struct Clock {
    double year;
    double month;
    double day;
};


struct Weight {
    double total;
    double max;
    double empty;
};
struct Engine {
    UINT32 engineType;
    UINT32 numEngines;

};
struct Gear {
    double extended;
    DWORD32 damaged;
    DWORD32 gearRetractable;
    DWORD32 skis;
    DWORD32 floats;
    DWORD32 skids;
    DWORD32 wheels;
    DWORD32 down;
};
struct Flaps {
    DWORD64 available;
    DWORD64 positions;
    DWORD64 handleIndex;
    DWORD64 damaged;
    DWORD64 speedExceeded;

};

struct ControlsDamage {


};

struct Controls {

};

struct AircraftData {
    char atcType[64];
    char atcmodel[64];
    char atcairline[64];
    char atcid[64];
    char atcFlightNum[8];
    //
};
struct Aircraft {
    struct Weight weight;
    struct Engine engine;
    struct Gear gear;
    struct Flaps flaps;
    struct Lights lights;
    struct AircraftData data;
};


struct DataRefs
{
    struct Sim sim;
    struct Env env;
    struct Alts altitude;
    struct Speed speed;
    struct Attitude attitude;
    struct Geo geo;
    struct Fuel fuel;
    struct Clock local;
    struct Aircraft aircraft;
};


HRESULT register_per_frame_data(HANDLE* hSimConnect, SIMCONNECT_DATA_DEFINITION_ID DEFINITION_ID);
HRESULT register_per_second_data(HANDLE* hSimConnect, SIMCONNECT_DATA_DEFINITION_ID DEFINITION_ID);

