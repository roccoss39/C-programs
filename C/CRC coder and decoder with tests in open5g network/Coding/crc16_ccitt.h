#ifndef CRC16_CCITT_H
#define CRC16_CCITT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define CRC_SIZE 2
#define LENGTH_SIZE 2

uint16_t crc16_ccitt(uint8_t *data, size_t data_length);

#endif // CRC16_H
