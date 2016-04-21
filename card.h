#ifndef __CARD_H__
#define __CARD_H__

#include <stdio.h>

#define NUM_SUITS 4
#define NUM_VALUES 13

// negative suit/value indicates field is not set
typedef struct card {
  int suit;  // spades, clubs, diamonds, hearts
  int value; // aces 0
} card_t;

void print_card(card_t* card);
void swap_cards(card_t* card1, card_t* card2);

#endif
