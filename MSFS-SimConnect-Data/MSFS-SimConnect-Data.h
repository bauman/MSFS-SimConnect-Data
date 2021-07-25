// MSFS-SimConnect-Data.h : Include file for standard system include files,
// or project specific include files.

#pragma once

enum DATA_DEFINE_ID
{
    DEFINITION_ID_AP,
    DEFINITION_ID_RL
};

enum DATA_REQUEST_ID
{
    REQUEST_AP_SETTINGS,
    REQUEST_RL_SETTINGS
};

enum EVENT_ID
{
    EVENT_SET_AP_ALTITUDE,
    EVENT_TEXT_1
};


bool prepare_data_requests(HANDLE* hSimConnect);
void data_collection_loop(HANDLE* hSimConnect);

// TODO: Reference additional headers your program requires here.
