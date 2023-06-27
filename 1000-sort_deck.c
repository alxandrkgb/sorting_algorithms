#include <stdlib.h>
#include "deck.h"

int card_value(const card_t *card);

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: The deck of cards to be sorted
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *node;
    card_t **cards;
    size_t deck_size = 0;
    size_t i, j;

    /* Count the number of cards in the deck */
    for (node = *deck; node != NULL; node = node->next)
        deck_size++;

    /* Allocate memory for an array of card pointers */
    cards = malloc(deck_size * sizeof(card_t *));
    if (cards == NULL)
        return;

    /* Copy the card pointers to the array */
    for (i = 0, node = *deck; node != NULL; i++, node = node->next)
        cards[i] = (card_t *)node->card;

    /* Perform bubble sort on the card pointers */
    for (i = 0; i < deck_size - 1; i++)
    {
        for (j = 0; j < deck_size - i - 1; j++)
        {
            if (card_value(cards[j]) > card_value(cards[j + 1]))
            {
                /* Swap the card pointers */
                card_t *temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }

    /* Update the deck with the sorted cards */
    for (i = 0, node = *deck; node != NULL; i++, node = node->next)
        node->card = (void *)cards[i];

    /* Free the allocated memory */
    free(cards);
}
