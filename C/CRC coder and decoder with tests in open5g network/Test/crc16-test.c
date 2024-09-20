#include "coding/encoder.h"
#include "coding/decoder.h"
#include "core/abts.h"

// Function testing encoding and decoding
static void test_encode_decode(abts_case *tc, void *data)
{
    // Test 1: Basic test with short data
    uint8_t test_data1[] = {0x12, 0x34, 0x56};
    size_t length1 = sizeof(test_data1) / sizeof(test_data1[0]);

    // // Encoding
    uint8_t *encoded_data1 = encode_data_with_crc(test_data1, length1);
    ABTS_PTR_NOTNULL(tc, encoded_data1);

    // // Decoding
    uint8_t *decoded_data1 = decode_data_with_crc(encoded_data1);
    ABTS_PTR_NOTNULL(tc, decoded_data1);

    // // Check if data before encoding is the same as after decoding
    ABTS_TRUE(tc, memcmp(test_data1, decoded_data1, length1) == 0);

    free(encoded_data1);
    free(decoded_data1);

    // Test 2: Longer data
    uint8_t test_data2[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    size_t length2 = sizeof(test_data2) / sizeof(test_data2[0]);

    // Encoding
    uint8_t *encoded_data2 = encode_data_with_crc(test_data2, length2);
    ABTS_PTR_NOTNULL(tc, encoded_data2);

    // Decoding
    uint8_t *decoded_data2 = decode_data_with_crc(encoded_data2);
    ABTS_PTR_NOTNULL(tc, decoded_data2);

    // Check if data before encoding is the same as after decoding
    ABTS_TRUE(tc, memcmp(test_data2, decoded_data2, length2) == 0);

    free(encoded_data2);
    free(decoded_data2);

    // Test 3: Data with a single byte
    uint8_t test_data3[] = {0xAA};
    size_t length3 = sizeof(test_data3) / sizeof(test_data3[0]);

    // Encoding
    uint8_t *encoded_data3 = encode_data_with_crc(test_data3, length3);
    ABTS_PTR_NOTNULL(tc, encoded_data3);

    // Decoding
    uint8_t *decoded_data3 = decode_data_with_crc(encoded_data3);
    ABTS_PTR_NOTNULL(tc, decoded_data3);

    // Check if data before encoding is the same as after decoding
    ABTS_TRUE(tc, memcmp(test_data3, decoded_data3, length3) == 0);

    free(encoded_data3);
    free(decoded_data3);

    // Test 4: Check if corrupted data detects bad CRC
    uint8_t test_data4[] = {0xAB, 0xCD, 0xEF};
    size_t length4 = sizeof(test_data4) / sizeof(test_data4[0]);

    // Encoding
    uint8_t *encoded_data4 = encode_data_with_crc(test_data4, length4);
    ABTS_PTR_NOTNULL(tc, encoded_data4); 

    // Modify data to induce CRC error
    encoded_data4[2] ^= 0xFF; 

    // Decoding with corrupted CRC (expecting NULL)
    uint8_t *decoded_data4 = decode_data_with_crc(encoded_data4);
    ABTS_PTR_EQUAL(tc, NULL, decoded_data4); 

    free(encoded_data4);

    // Test 5: Check if functions handle NULL input correctly
    uint8_t *encoded_data5 = encode_data_with_crc(NULL, 0);
    ABTS_PTR_EQUAL(tc, NULL, encoded_data5); 
}

// Test 6: Very large data
static void test_large_data(abts_case *tc, void *data)
{
    size_t length = MAX_PACKET_SIZE_BYTE; 
    uint8_t *test_data = (uint8_t *)malloc(length);
    memset(test_data, 0x55, length); // Fill with data

    uint8_t *encoded_data = encode_data_with_crc(test_data, length);
    ABTS_PTR_NOTNULL(tc, encoded_data);

    uint8_t *decoded_data = decode_data_with_crc(encoded_data);
    ABTS_PTR_NOTNULL(tc, decoded_data);

    ABTS_TRUE(tc, memcmp(test_data, decoded_data, length) == 0);

    free(test_data);
    free(encoded_data);
    free(decoded_data);
}

// Test 7: Data filled with zeros
static void test_zero_filled_data(abts_case *tc, void *data)
{
    uint8_t test_data[] = {0x00, 0x00, 0x00, 0x00};
    size_t length = sizeof(test_data);

    uint8_t *encoded_data = encode_data_with_crc(test_data, length);
    ABTS_PTR_NOTNULL(tc, encoded_data);

    uint8_t *decoded_data = decode_data_with_crc(encoded_data);
    ABTS_PTR_NOTNULL(tc, decoded_data);

    ABTS_TRUE(tc, memcmp(test_data, decoded_data, length) == 0);

    free(encoded_data);
    free(decoded_data);
}

// Test 8: Data filled with maximum byte values (0xFF)
static void test_max_byte_data(abts_case *tc, void *data)
{
    uint8_t test_data[] = {0xFF, 0xFF, 0xFF, 0xFF};
    size_t length = sizeof(test_data);

    uint8_t *encoded_data = encode_data_with_crc(test_data, length);
    ABTS_PTR_NOTNULL(tc, encoded_data);

    uint8_t *decoded_data = decode_data_with_crc(encoded_data);
    ABTS_PTR_NOTNULL(tc, decoded_data);

    ABTS_TRUE(tc, memcmp(test_data, decoded_data, length) == 0);

    free(encoded_data);
    free(decoded_data);
}

// Test 9: Decoding empty data
static void test_empty_data_decode(abts_case *tc, void *data)
{
    uint8_t *decoded_data = decode_data_with_crc(NULL);
    ABTS_PTR_EQUAL(tc, NULL, decoded_data); // Expect NULL
}

// Test 10: Completely corrupted data (bad CRC)
static void test_corrupted_data(abts_case *tc, void *data)
{
    uint8_t test_data[] = {0x12, 0x34, 0x56};
    size_t length = sizeof(test_data);

    uint8_t *encoded_data = encode_data_with_crc(test_data, length);
    ABTS_PTR_NOTNULL(tc, encoded_data);
    size_t i;
   
    for (i = 0; i < length + 2; ++i)
    {
        encoded_data[i] ^= 0xFF;
    }

    uint8_t *decoded_data = decode_data_with_crc(encoded_data);
    ABTS_PTR_NOTNULL(tc, encoded_data); // Expect CRC error

    free(encoded_data);
}

// Test 11: Overflow data
static void test_overflow_data(abts_case *tc, void *data)
{
    size_t length = MAX_PACKET_SIZE_BYTE + 1; 
    uint8_t *test_data = (uint8_t *)malloc(length);
    memset(test_data, 0x55, length); // Fill with data

    uint8_t *encoded_data = encode_data_with_crc(test_data, length);
    ABTS_PTR_EQUAL(tc, NULL, encoded_data);

    uint8_t *decoded_data = decode_data_with_crc(encoded_data);
    ABTS_PTR_EQUAL(tc, NULL, decoded_data);

    free(test_data);
    free(encoded_data);
    free(decoded_data);
}

// Function to register tests
abts_suite *test_crc16(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, test_encode_decode, NULL);
    abts_run_test(suite, test_large_data, NULL);
    abts_run_test(suite, test_zero_filled_data, NULL);
    abts_run_test(suite, test_max_byte_data, NULL);
    abts_run_test(suite, test_empty_data_decode, NULL);
    abts_run_test(suite, test_corrupted_data, NULL);
    abts_run_test(suite, test_overflow_data, NULL);

    return suite;
}
