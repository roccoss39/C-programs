#include "crc16_ccitt.h"
#include "decoder.h"

uint8_t *decode_data_with_crc(uint8_t *data)
{
    if (data == NULL)
        return NULL;

    size_t data_length = (data[0] << 8) | data[1];
    uint16_t received_crc = (data[data_length + LENGTH_SIZE] << 8) | data[data_length + LENGTH_SIZE + 1];
    uint16_t calculated_crc = crc16_ccitt(data + LENGTH_SIZE, data_length);

    if (calculated_crc != received_crc)
    {
        fprintf(stderr, "Error: CRC mismatch! Received: 0x%04X, Expected: 0x%04X\n", received_crc, calculated_crc);
        return NULL;
    }

    // Memory will be free after data handling
    uint8_t *decoded_data = (uint8_t *)malloc(data_length);
    if (!decoded_data)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }

    memcpy(decoded_data, data + LENGTH_SIZE, data_length);

    return decoded_data;
}