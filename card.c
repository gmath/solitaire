#include "card.h"

void print_card(card_t* card) {
  printf("suit %d, value %d\n", card->suit, card->value);
}

void swap_cards(card_t* card1, card_t* card2) {
  card_t tmp;
  tmp	 = *card1;
  *card1 = *card2;
  *card2 = tmp;
}
