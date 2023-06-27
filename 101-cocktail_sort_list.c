#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *prev_node1, *prev_node2, *next_node1, *next_node2;

    prev_node1 = (*node1)->prev;
    prev_node2 = (*node2)->prev;
    next_node1 = (*node1)->next;
    next_node2 = (*node2)->next;

    if (prev_node1)
        prev_node1->next = *node2;
    if (prev_node2)
        prev_node2->next = *node1;

    (*node1)->prev = prev_node2;
    (*node1)->next = next_node2;
    (*node2)->prev = prev_node1;
    (*node2)->next = next_node1;

    if (next_node1)
        next_node1->prev = *node2;
    if (next_node2)
        next_node2->prev = *node1;

    if (!prev_node1)
        *list = *node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the cocktail sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &current->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (current = current->prev; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &current->prev, &current);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}
