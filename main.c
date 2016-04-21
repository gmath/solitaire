#include <stdlib.h>
#include <stdbool.h>
#include "card.h"
#include "deck.h"
#include "game.h"

void normalize(uint32_t* arr, size_t arr_size, size_t normalization_factor, double* normalized_arr) {

  size_t i;
  for ( i = 0; i < arr_size; ++i ) {
    normalized_arr[i] = (double) arr[i] / (double) normalization_factor;
  }
}

size_t sum(const uint32_t* arr, size_t arr_size) {

  size_t i;
  size_t sum = 0;

  for ( i = 0; i < arr_size; ++i ) {
    sum += arr[i];
  }

  return sum;
}

int main(int argc, char* argv[]) {

  /* get user input number of simulation */
  uint32_t num_simulations = atoi(argv[1]);

  /* get a random seed */
  srand(time(NULL));

  /* define and initialize a deck */
  deck_t deck;
  deck.capacity = 52;
  deck.size     = 0; 
  deck.cards    = (card_t*)malloc(deck.capacity);

  /* define a game */
  game_t game;

  /* define the counters for keeping stats */
  uint32_t grid_counter[GRID_SIZE] = {0};
  uint32_t win_counter[WIN_SIZE] = {0};

  /* run the simulation */
  uint32_t i;
  for ( i = 0; i < num_simulations; ++i ) {

    /* reset deck state */
    reset_deck_state(&deck);

    /* reset game state */
    reset_game_state(&game);

    /* play the game */
    while ( true ) {

      int hand_result = play_hand(&game, &deck, grid_counter);
      if ( hand_result == GAME_OVER )
	break;

    }

    /* keep a record of the number of grid elements used */
    ++win_counter[game.num_elements];

  }

  /* count and display the total number of wins */
  size_t total_win_count = sum(win_counter, WIN_SIZE);
  printf("total wins %zu\n", total_win_count);

  /* compute win_percentages */
  double win_probabilities[WIN_SIZE];
  normalize(win_counter, WIN_SIZE, total_win_count, win_probabilities);

  /* print win percentages and counts */
  uint32_t j;
  for ( j = 0; j < WIN_SIZE; ++j ) {
    printf("win_probabilities[%d] = %f \t win_counter[%d] = %d\n", j, win_probabilities[j], j, win_counter[j]);
  }
  
  return 0;
}
