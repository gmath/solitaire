#ifndef __GAME_H__
#define __GAME_H__

#include "card.h"
#include "deck.h"

#define GRID_SIZE NUM_VALUES + 1
#define WIN_SIZE GRID_SIZE + 1
#define GAME_OVER -2

typedef struct game {
  uint8_t num_moves;      // how many moves to play the game
  uint8_t num_elements;   // how many cards dealt into the grid
  uint8_t num_hands;      // how many hands dealt into the grid
  card_t grid[GRID_SIZE]; // the game grid
} game_t;

typedef struct pair {
  uint8_t first;   // index of the first match
  uint8_t second;  // index of the second match
} pair_t;

void print_game_grid(game_t* game);
void print_matching_pair(pair_t* index_pair);
void reset_game_state(game_t* game);
int find_matching_pair(game_t* game, pair_t* index_pair);
int play_hand(game_t* game, deck_t* deck, uint32_t grid_counter[GRID_SIZE]);

#endif
