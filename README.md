# solitaire
solitaire variation simulation

the game:
deal cards into a grid and if there is a match,
draw cards on top of the match.

aggregate win statistics that track the number of
grid spots used in order to win the game

compile:
gcc main.c deck.c card.c game.c -o solitaire

running: ( with timing it )
time ./solitaire <num_simulations>

for example ( simulate with 1M games )
time ./solitaire 1000000

total wins 1000000
win_probabilities[0] = 0.000000 	 win_counter[0] = 0
win_probabilities[1] = 0.000000 	 win_counter[1] = 0
win_probabilities[2] = 0.000000 	 win_counter[2] = 0
win_probabilities[3] = 0.000000 	 win_counter[3] = 0
win_probabilities[4] = 0.000000 	 win_counter[4] = 0
win_probabilities[5] = 0.000000 	 win_counter[5] = 0
win_probabilities[6] = 0.000118 	 win_counter[6] = 118
win_probabilities[7] = 0.000000 	 win_counter[7] = 0
win_probabilities[8] = 0.053664 	 win_counter[8] = 53664
win_probabilities[9] = 0.000000 	 win_counter[9] = 0
win_probabilities[10] = 0.513471 	 win_counter[10] = 513471
win_probabilities[11] = 0.000000 	 win_counter[11] = 0
win_probabilities[12] = 0.400637 	 win_counter[12] = 400637
win_probabilities[13] = 0.000000 	 win_counter[13] = 0
win_probabilities[14] = 0.032110 	 win_counter[14] = 32110

real	0m10.448s
user	0m10.444s
sys	0m0.000s
