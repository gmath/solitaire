#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "card.h"

void print_deck(deck_t* deck) {
  uint8_t i;
  for ( i = 0; i < deck->size; ++i) 
    print_card(&deck->cards[i]);
}

int deal_card(deck_t* deck, card_t* card) {

  if ( deck->size == 0 )
    return -1;

  *card = deck->cards[--deck->size];
  return 0;

}
void shuffle_deck(deck_t* deck) {

  // iterate through the deck
  // generate a random number r in [0, size -1]
  // swap card i with card r

  uint8_t i;
  uint8_t r;
  for ( i = 0; i < deck->size; ++i ) {
    r = rand_lim(deck->size - 1);
    swap_cards(&deck->cards[i], &deck->cards[r]);
  }

}

void push(card_t* card, deck_t* deck) {
  deck->cards[deck->size++] = *card;
}

void fill_deck(deck_t* deck) {

  uint8_t suit;
  uint8_t value;

  card_t current_card;
  for ( suit = 0; suit < NUM_SUITS; ++suit ) {
    for ( value = 0; value < NUM_VALUES; ++value ) {
      current_card.suit	 = suit;
      current_card.value = value;
      push(&current_card, deck);
    }
  }

}

void reset_deck_state(deck_t* deck) {
    fill_deck(deck);
    shuffle_deck(deck);
    shuffle_deck(deck);
}

/* taken from stack overflow */
int rand_lim(int limit) {
  /* return a random number between 0 and limit inclusive. */
  int divisor = RAND_MAX/(limit+1);
  int retval;

  do { 
    retval = rand() / divisor;
  } while (retval > limit);

  return retval;
}
