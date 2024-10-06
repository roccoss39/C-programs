#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cjson/cJSON.h>
#include <string.h>
#include "threads.h"


#define BUFFER_SIZE 64
#define MAX_CONNECTIONS 15
#define MAX_SIGNAL_STRENGTH 1023
#define MAX_CONFIG_PRESET 10
#define MAX_MCS 31
#define MAX_TBS 127
#define CONNECTION_REQUEST_SIGNAL_TYPE 1
#define DOWNLINK_DATA_SIGNAL_TYPE 4
#define HEADER_OFFSET 3
#define DATA_OFFSET 4

static char sharedBuffer[BUFFER_SIZE];
static bool bufferReady = false;
static bool finishTransmit = false;

pthread_mutex_t mutexLock;
pthread_cond_t cond;

int main()
{
    pthread_t _transmitThread;
    pthread_t _receiverThread;

    pthread_mutex_init(&mutexLock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&_transmitThread, NULL, transmitThread, "/mnt/c/Users/podzi/Desktop/programowanie/C/threads/src/input.in");
    pthread_create(&_receiverThread, NULL, receiverThread, "/mnt/c/Users/podzi/Desktop/programowanie/C/threads/src/output.out");

    pthread_join(_transmitThread, NULL);
    pthread_join(_receiverThread, NULL);

    pthread_mutex_destroy(&mutexLock);
    pthread_cond_destroy(&cond);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void *transmitThread(void *fileName)
{
    
    FILE *pFile = fopen((char *)fileName, "r");
    if (pFile == NULL)
    {
        perror("Cannot open input file");
        exit(EXIT_FAILURE);
    }

    while (fgets(sharedBuffer, sizeof(sharedBuffer), pFile) != NULL)
    {
        if (checkInput(sharedBuffer))
        {
        pthread_mutex_lock(&mutexLock);
        bufferReady = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutexLock);

        // Waiting for receiverThread
        pthread_mutex_lock(&mutexLock);
        while (bufferReady)
        {
            pthread_cond_wait(&cond, &mutexLock);
        }
        pthread_mutex_unlock(&mutexLock);
        }
    }

    fclose(pFile);

    pthread_mutex_lock(&mutexLock);
    finishTransmit = true;
    bufferReady = true;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutexLock);

    return NULL;
}

void *receiverThread(void *fileName)
{
    FILE *outputFile = fopen((char *)fileName, "w");
    if (outputFile == NULL)
    {
        perror("Cannot open output file");
        exit(EXIT_FAILURE);
    }

    while (!finishTransmit)
    {
        pthread_mutex_lock(&mutexLock);
        while (!bufferReady && !finishTransmit)
        {
            pthread_cond_wait(&cond, &mutexLock);
        }
        if (!finishTransmit)
        {
            printf("sharedbuf:%s\n", sharedBuffer);
            if (sharedBuffer[0] == '1')
            {
                connectionRequest_t connectionRequest;
                unsigned int signalType, signalSize, connectionId, configPreset, signalStrength;

                sscanf(sharedBuffer, "%d %d %d %d %d",
                       &signalType,
                       &signalSize,
                       &connectionId,
                       &configPreset,
                       &signalStrength);

                connectionRequest.header.signalType = signalType;
                connectionRequest.header.signalSize = signalSize;
                connectionRequest.connectionId = connectionId;
                connectionRequest.configPreset = configPreset;
                connectionRequest.signalStrength = signalStrength;

                char *jsonString = connectionRequestToJson(&connectionRequest);
                fputs(jsonRemoveSpacesAroundColons(jsonString), outputFile);
                fputs("\n", outputFile);
                free(jsonString);
            }
            else if (sharedBuffer[0] == '4')
            {
                downlinkData downlink;
                unsigned int signalType, signalSize, noOfConnections;

                sscanf(sharedBuffer, "%d %d %d",
                       &signalType, &signalSize, &noOfConnections);

                downlink.header.signalType = signalType;
                downlink.header.signalSize = signalSize;
                downlink.noOfConnections = noOfConnections;

                downlink.details = (connectionDownlinkDataDetails *)malloc(noOfConnections * sizeof(connectionDownlinkDataDetails));

                const char *bufferPtr = sharedBuffer;
                uint8_t spaces = 0;
                while (spaces < HEADER_OFFSET)
                {
                    if (*bufferPtr++ == ' ')
                        spaces++;
                }
                printf("sharedbuf przed petla:%s\n", bufferPtr);
                for (int i = 0; i < noOfConnections; i++)
                {
                    unsigned int connectionId, mcs, tbs, dataSize;
                    sscanf(bufferPtr, "%d %d %d %d",
                           &connectionId,
                           &mcs,
                           &tbs,
                           &dataSize);

                    downlink.details[i].connectionId = connectionId;
                    downlink.details[i].mcs = mcs;
                    downlink.details[i].tbs = tbs;
                    downlink.details[i].dataSize = dataSize;

                    spaces = 0;
                    while (spaces < DATA_OFFSET && *bufferPtr != '\0')
                    {
                        if (*bufferPtr++ == ' ')
                            spaces++;
                    }
                }

                // JSON Convertion
                char *jsonString = downlinkDataToJson(&downlink);
                fputs(jsonRemoveSpacesAroundColons(jsonString), outputFile);
                fputs("\n", outputFile);

                free(downlink.details);
                free(jsonString);
            }

            bufferReady = false;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutexLock);
        }
    }

    fclose(outputFile);
    return NULL;
}

char *connectionRequestToJson(connectionRequest_t *connectionRequest)
{
    cJSON *json = cJSON_CreateObject();
    cJSON *jsonConnectionRequest = cJSON_CreateObject();
    cJSON_AddItemToObject(json, "ConnectionRequest", jsonConnectionRequest);

    cJSON *jsonHeader = cJSON_CreateObject();
    cJSON_AddItemToObject(jsonConnectionRequest, "header", jsonHeader);

    cJSON_AddNumberToObject(jsonHeader, "signalType", connectionRequest->header.signalType);
    cJSON_AddNumberToObject(jsonHeader, "signalSize", connectionRequest->header.signalSize);

    cJSON_AddNumberToObject(jsonConnectionRequest, "connectionId", connectionRequest->connectionId);
    cJSON_AddNumberToObject(jsonConnectionRequest, "configPreset", connectionRequest->configPreset);
    cJSON_AddNumberToObject(jsonConnectionRequest, "signalStrength", connectionRequest->signalStrength);

    // Converting the JSON object to a string
    char *jsonString = cJSON_Print(json);

    cJSON_Delete(json);

    return jsonString;
}

char *downlinkDataToJson(downlinkData *data)
{
    cJSON *json = cJSON_CreateObject();

    cJSON *jsonDownlinkData = cJSON_CreateObject();
    cJSON_AddItemToObject(json, "DownlinkData", jsonDownlinkData);

    cJSON *jsonHeader = cJSON_CreateObject();
    cJSON_AddItemToObject(jsonDownlinkData, "header", jsonHeader);

    cJSON_AddNumberToObject(jsonHeader, "signalType", data->header.signalType);
    cJSON_AddNumberToObject(jsonHeader, "signalSize", data->header.signalSize);

    cJSON_AddNumberToObject(jsonDownlinkData, "noOfConnections", data->noOfConnections);

    cJSON *jsonDetailsArray = cJSON_CreateArray();
    cJSON_AddItemToObject(jsonDownlinkData, "connectionDownlinkDataDetails", jsonDetailsArray);

    for (int i = 0; i < data->noOfConnections; i++)
    {
        cJSON *jsonDetail = cJSON_CreateObject();
        cJSON_AddNumberToObject(jsonDetail, "connectionId", data->details[i].connectionId);
        cJSON_AddNumberToObject(jsonDetail, "mcs", data->details[i].mcs);
        cJSON_AddNumberToObject(jsonDetail, "tbs", data->details[i].tbs);
        cJSON_AddNumberToObject(jsonDetail, "dataSize", data->details[i].dataSize);
        cJSON_AddItemToArray(jsonDetailsArray, jsonDetail);
    }

    char *jsonString = cJSON_Print(json);

    cJSON_Delete(json);

    return jsonString;
}

char *jsonRemoveSpacesAroundColons(const char *jsonString)
{
    if (jsonString == NULL)
    {
        return NULL;
    }

    char *destString = malloc(strlen(jsonString) + 1);
    if (destString == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    const char *src = jsonString;
    char *destS = destString;

    while (*src != '\0')
    {
        *destS++ = *src;
        if (*src == ':')
        {
            src++;
            if (*src == '\t')
            {
                src++;
                *destS++ = ' ';
            }
        }
        else
        {
            src++;
        }
    }
    *destS = '\0';

    return destString;
}

bool checkInput(const char *buffer)
{
    if (buffer[0] == '1')
    {
        unsigned int signalType, signalSize, connectionId, configPreset, signalStrength;
        sscanf(buffer, "%d %d %d %d %d",
               &signalType,
               &signalSize,
               &connectionId,
               &configPreset,
               &signalStrength);

        if (signalType != CONNECTION_REQUEST_SIGNAL_TYPE || signalSize <= 0)
        {
            return false;
        }

        if (configPreset > MAX_CONFIG_PRESET)
        {
            return false;
        }

        if (signalStrength > MAX_SIGNAL_STRENGTH)
        {
            return false;
        }
    }
    else if (buffer[0] == '4')
    {
        unsigned int signalType, signalSize, noOfConnections;
        sscanf(buffer, "%d %d %d",
               &signalType,
               &signalSize,
               &noOfConnections);

        if (signalType != DOWNLINK_DATA_SIGNAL_TYPE || signalSize <= 0)
        {
            return false;
        }

        if (noOfConnections > MAX_CONNECTIONS)
        {
            return false;
        }

        const char *bufferPtr = buffer;
        uint8_t spaces = 0;
        while (spaces < HEADER_OFFSET)
        {
            if (*bufferPtr++ == ' ')
                spaces++;
        }

        for (int i = 0; i < noOfConnections; i++)
        {
            unsigned int connectionId, mcs, tbs, dataSize;
            sscanf(bufferPtr, "%d %d %d %d",
                   &connectionId,
                   &mcs,
                   &tbs,
                   &dataSize);

            if (mcs > MAX_MCS)
            {
                return false;
            }

            if (tbs > MAX_TBS)
            {
                return false;
            }

            uint8_t spaces = 0;
            while (spaces < DATA_OFFSET && *bufferPtr != '\0')
            {
                if (*bufferPtr++ == ' ')
                    spaces++;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}
