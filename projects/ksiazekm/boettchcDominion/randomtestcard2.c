#include "dominion.h"
#include <stdio.h>
//test minion
int main() {
	srand(time(NULL));
	struct gameState state;
	int result, rando = 0, player = 1, handCount, deckCount, good = 0, bad = 0, j, i;
	int handpos = 0, choice1 = 0, choice2 = 0, bonus = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, silver, copper,
			duchy, province, great_hall };
	int run;
	printf("Testing minion()\n");

	for (run = 0; run < 5000; run++)
	{
		int numPlayers = rand() % 4;
		int gameSeed = rand() % 5000;
		choice1 = rand() % 2;
		choice2 = rand() % 2;
		if (!choice1) {
			choice2 = 1;
		}
		initializeGame(numPlayers, k, gameSeed, &state);
		result = playMinion(&state, choice1, choice2, handpos);

	}
	printf("End Testing minion()");

	return 0;
}
