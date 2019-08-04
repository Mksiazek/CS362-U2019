#include "dominion.h"
#include <stdio.h>
//test tribute
int main() {
	srand(time(NULL));
	struct gameState state;
	int result;
	int handpos = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, silver, copper,
			duchy, province, great_hall };
	int run;
	printf("Testing tribute()\n");

	for (run = 0; run < 5000; run++)
	{
		int numPlayers = rand() % 4;
		int gameSeed = rand() % 5000;
		initializeGame(numPlayers, k, gameSeed, &state);
		result = tributeFunction(&state);
	}
	printf("End Testing tribute()");

	return 0;
}
