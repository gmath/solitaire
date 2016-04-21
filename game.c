#include "game.h"

void print_matching_pair(pair_t* index_pair) {
  printf("first index = %d, last index = %d\n", index_pair->first, index_pair->second);
}

void print_game_grid(game_t* game) {

  uint8_t i;
  for ( i = 0; i < game->num_elements; ++i ) {
    printf("grid[%d] = ", i);
    print_card(&game->grid[i]);
  }
}

void reset_game_state(game_t* game) {
  game->num_elements = 0;
  game->num_moves    = 0;
  game->num_hands    = 1;

  uint8_t i;
  card_t card;
  for ( i = 0; i < GRID_SIZE; ++i ) {
    card.suit  = -1;
    card.value = -1;
    game->grid[i] = card;
  }
}

int find_matching_pair(game_t* game, pair_t* index_pair) {

  // initialize the return locations ( not found )
  index_pair->first  = -1;
  index_pair->second = -1;

  /* start at the first game grid position
     and search for the first matching pair */

  uint8_t i;
  uint8_t j;
  for ( i = 0; i < game->num_elements; ++i ) {
    for ( j = i + 1; j < game->num_elements; ++j ) {

      // found a card with the same value 
      if ( game->grid[i].value == game->grid[j].value ) {
	index_pair->first  = i;
	index_pair->second = j;
	return 0;
      }
    }
  }

  // did not find two cards with matching values in the game grid
  return -1;
}

int play_hand(game_t* game, deck_t* deck, uint32_t grid_counter[GRID_SIZE]) {

  // if fail to deal card, deck is empty
  card_t card;
  if ( 0 > deal_card(deck, &card) )
    return GAME_OVER;

  // guarenteed to deal at least 1 card, hence a hand
  ++game->num_hands;

  // if no matching pairs, assign dealt card to free space
  pair_t index_pair;
  if ( 0 > find_matching_pair(game, &index_pair) ) {
    game->grid[game->num_elements++] = card;
    ++game->num_moves;
    return 0;
  }

  // if matching pair, try to deal a second card
  // if the deck is empty, assign the dealt card to the free space
  card_t second_card;
  if ( 0 > deal_card(deck, &second_card) ) {
    game->grid[game->num_elements++] = card;
    ++game->num_moves;
    return GAME_OVER;
  }

  // assign the two dealt cards on top of the matching pair
  game->grid[index_pair.first]  = card;
  ++grid_counter[index_pair.first];
  ++game->num_moves;

  game->grid[index_pair.second] = second_card;
  ++grid_counter[index_pair.second];
  ++game->num_moves;

  return 0;
}
