#ifndef __DECK_H__
#define __DECK_H__

#include <stdint.h>
#include "card.h"

typedef struct deck {
  uint8_t capacity; // number of cards in a full deck
  uint8_t size;     // number of cards in the current deck
  card_t* cards;    // pointer to array of cards
} deck_t;

void print_deck(deck_t* deck);
int deal_card(deck_t* deck, card_t* card);
void shuffle_deck(deck_t* deck);
void push(card_t* card, deck_t* deck);
void fill_deck(deck_t* deck);
void reset_deck_state(deck_t* deck);
int rand_lim(int limit);

#endif
