#include "crc16_ccitt.h"
#include "encoder.h"

uint8_t *encode_data_with_crc(uint8_t *data, size_t data_length)
{

    if ((data == NULL) || (data_length < 1) || (data_length > MAX_PACKET_SIZE_BYTE))
    {
        fprintf(stderr, "Invalid input data\n");
        return NULL;
    }

    uint16_t crc = crc16_ccitt(data, data_length);
    size_t encoded_data_length = data_length + LENGTH_SIZE + CRC_SIZE;

    // Memory will be free after transmiting
    uint8_t *encoded_data = (uint8_t *)malloc(encoded_data_length);
    if (!encoded_data)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    memcpy(encoded_data + LENGTH_SIZE, data, data_length);

    encoded_data[encoded_data_length - CRC_SIZE] = (crc >> 8) & 0xFF; // High byte of CRC
    encoded_data[encoded_data_length - CRC_SIZE + 1] = crc & 0xFF;    // Low byte of CRC

    encoded_data[0] = (data_length >> 8) & 0xFF;
    encoded_data[1] = data_length & 0xFF;

    return encoded_data;
}
