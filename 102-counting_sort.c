#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max_value, i, j;

    if (array == NULL || size < 2)
        return;

    max_value = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    count = malloc((max_value + 1) * sizeof(int));
    if (count == NULL)
        return;

    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (i = 0; i <= max_value; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    for (i = 1; i <= max_value; i++)
        count[i] += count[i - 1];

    print_array(count, max_value + 1);

    for (j = (int)size - 1; j >= 0; j--)
    {
        output[count[array[j]] - 1] = array[j];
        count[array[j]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
