#ifndef THREADS_H
#define THREADS_H

#include <stdint.h>

typedef struct
{
    uint16_t signalType : 4;
    uint16_t signalSize : 12;
} header;

typedef struct
{
    header header;
    uint32_t connectionId;
    uint16_t configPreset : 4;
    uint16_t signalStrength : 10;
} connectionRequest_t;

typedef struct
{
    uint32_t connectionId;
    uint16_t mcs : 5;
    uint16_t tbs : 7;
    uint32_t dataSize;
} connectionDownlinkDataDetails;

typedef struct
{
    header header;
    uint16_t noOfConnections : 4;
    connectionDownlinkDataDetails *details;
} downlinkData;

void *transmitThread(void *fileName);
void *receiverThread(void *fileName);
char *connectionRequestToJson(connectionRequest_t *connectionRequest);
char *jsonRemoveSpacesAroundColons(const char *jsonString);
char *downlinkDataToJson(downlinkData *data);
bool checkInput(const char *buffer);

#endif