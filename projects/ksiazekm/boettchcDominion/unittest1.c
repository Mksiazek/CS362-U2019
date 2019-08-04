/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 //This was copied from testUpdateCoins.c in Week 3 Modules as a template
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

 // set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int bonus;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int maxHandCount = 5;
	// arrays of all coppers, silvers, and golds
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	int golds[MAX_HAND];
	int estates[MAX_HAND];
	int choice1 = 1; // boolean true or going to discard an estate
	for (i = 0; i < MAX_HAND; i++)
	{
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
		estates[i] = estate;
	}

	printf("TESTING baron():\n");
#if (NOISY_TEST == 1)
	printf("Test baron %d with %d estate card(s)\n", p, handCount);
#endif
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game
	state.handCount[p] = handCount;                 // set the number of cards on hand
	memcpy(state.hand[p], estates, sizeof(int) * handCount); // set all cards to estate
	int result = playBaron(state, choice1);
	assert(state.coins == handCount + 4); // check if the number of coins is correct. This is when an estate is found, 4 coins are added to the hand

	printf("All tests passed!\n");

	return 0;
}