#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_DIM_ARR 2
#define MAX_COMBINATIONS 1000
#define SIZE_ARR 30
#define NUM_BITS 4

static int result[MAX_COMBINATIONS];
static int dim_arr[SIZE_DIM_ARR][SIZE_DIM_ARR][SIZE_DIM_ARR][SIZE_DIM_ARR];

static const char DGF[] = "DGF + ";
static const char HEC[] = "HEC + ";
static const char GER[] = "GER + ";
static const char FRS[] = "FRS + ";

static void filling_array(int t[][SIZE_DIM_ARR][SIZE_DIM_ARR][SIZE_DIM_ARR]);
static void display(int arr[]);
static int compare(const void *a, const void *b);
static void composite_abbreviations(int arr[], int i);

int main()
{
    srand((unsigned int)time(0));
    filling_array(dim_arr);
    qsort(result, MAX_COMBINATIONS, sizeof(int), compare);
    display(result);
    return 0;
}

void filling_array(int binary_array[][SIZE_DIM_ARR][SIZE_DIM_ARR][SIZE_DIM_ARR])
{
    for (int x = 0; x < MAX_COMBINATIONS; x++)
    {
        int i = rand() % SIZE_DIM_ARR;
        int j = rand() % SIZE_DIM_ARR;
        int n = rand() % SIZE_DIM_ARR;
        int m = rand() % SIZE_DIM_ARR;

        binary_array[i][j][n][m] = i * (1 << 3) + j * (1 << 2) + n * (1 << 1) + m; // bit value
        result[x] = binary_array[i][j][n][m];
        composite_abbreviations(result, x);
    }
}

int compare(const void *a, const void *b)
{
    int count_a = __builtin_popcount(*(int *)a); 
    int count_b = __builtin_popcount(*(int *)b);
    return count_a - count_b;
}

void display(int arr[])
{
    for (int i = 0; i < MAX_COMBINATIONS; i++)
    {
        bool displayed = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                displayed = true;
                break;
            }
        }
        if (!displayed)
        {
            int number = arr[i];
            int total = 0;
            composite_abbreviations(arr, i);
            printf("COMBINATIONS: ");

            for (int k = 0; k < MAX_COMBINATIONS; k++)
            {
                if (number == arr[k])
                    total++;
            }
            printf(" %d TIMES\n", total);
        }
    }
}

void composite_abbreviations(int arr[], int i)
{
    const char *labels[] = {FRS, GER, HEC, DGF};
    char array[SIZE_ARR] = ""; 
    
    for (int bit = 0; bit < NUM_BITS; bit++)
    {
        if ((arr[i] >> bit) & 1)
        {
            strncat(array, labels[bit], SIZE_ARR - strlen(array) - 1);
        }
    }

    if (strlen(array) == 0)
    {
        strncat(array, "NONE", SIZE_ARR - strlen(array) - 1);
    }

    size_t len = strlen(array);
    if (len > 3 && array[len - 2] == '+')
    {
        array[len - 3] = '\0';
    }

    printf("%s\n", array);
}
