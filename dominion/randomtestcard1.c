#include "dominion.h"
#include <stdio.h>
//test baron
void main()
{
	srand(time(NULL));

	int result;
	int handpos = 0, choice1 = 0, bonus = 0;
    int run = 0;
	struct gameState state;
	int k[10] = { adventurer, estate, village, minion, mine, cutpurse, copper,
			duchy, province, great_hall };

  for (run = 0; run < 5000; run++)
  	{
  		int numPlayers = rand() % 4;
  		int gameSeed = rand() % 5000;
  		choice1 = rand() % 2;
  		initializeGame(numPlayers, k, gameSeed, &state);
		printf("Testing baron()");
		result = baronFunction(&state, choice1);		
	}
	printf("End Testing baron()");

	return 0;
}