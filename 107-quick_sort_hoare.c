#include "sort.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick Sort algorithm (Hoare partition scheme)
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_partition(array, size, 0, size - 1);
}

/**
 * hoare_partition - Partitions the array using Hoare partition scheme
 * @array: The array of integers to be partitioned
 * @size: The size of the array
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 *
 * Return: The partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_int(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap_int - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
