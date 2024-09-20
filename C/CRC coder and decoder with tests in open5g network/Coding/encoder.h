#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>
#include <stddef.h>

#define MAX_PACKET_SIZE_BYTE 65535

uint8_t *encode_data_with_crc(uint8_t *data, size_t data_length);

#endif // ENCODER_H
