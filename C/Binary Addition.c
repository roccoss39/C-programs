#include <stdio.h>
#include <limits.h>
/* Implement a function that adds two numbers together and returns their sum in binary.
The conversion can be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary) */
char *binary_add(unsigned a, unsigned b, char *binary)
{
    // write to the binary string and return it
    long long unsigned int sum = (unsigned long long)a + (unsigned long long)b;
    int index = 0;
    char temp;

    if (sum == 0)
    {
        binary[0] = '0';
        binary[1] = '\0';
        return binary;
    }

    while (sum >= 1)
    {
        binary[index] = (sum % 2) + '0';
        index++;
        sum /= 2;
    }
    binary[index] = '\0';

    for (int i = 0; i < index / 2; i++)
    {
        temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }

    return binary;
}

int main()
{
    char binary[34];
    int i = 0;
    binary_add(UINT_MAX, UINT_MAX, binary);

    while (binary[i] != '\0')
    {
        printf("%c", binary[i]);
        i++;
    }
}