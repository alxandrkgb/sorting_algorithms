#include "sort.h"
#include <stdlib.h>

/**
 * counting_sortt - Performs counting sort on an array of integers
 * @array: The array of integers to be sorted
 * @size: The size of the array
 * @exp: The current exponent to use for sorting
 */
void counting_sortt(int *array, size_t size, int exp);

/**
 * radix_sort - Sorts an array of integers using the Radix sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max_value = 0, exp = 1;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Perform counting sort for every digit */
    while (max_value / exp > 0)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
        exp *= 10;
    }
}

/**
 * counting_sortt - Performs counting sort on an array of integers
 * @array: The array of integers to be sorted
 * @size: The size of the array
 * @exp: The current exponent to use for sorting
 */
void counting_sortt(int *array, size_t size, int exp)
{
    int *count, *output;
    size_t i;
    int max_value = 10; /* Maximum possible digit value */

    count = malloc(sizeof(int) * max_value);
    output = malloc(sizeof(int) * size);

    if (count == NULL || output == NULL)
    {
        free(count);
        free(output);
        return;
    }

    /* Initialize count array */
    for (i = 0; i < max_value; i++)
        count[i] = 0;

    /* Store count of occurrences in count[] */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] so that count[i] contains the actual
     * position of this digit in output[] */
    for (i = 1; i < max_value; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; i < (size_t)-1; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
