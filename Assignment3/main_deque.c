#include <stdio.h>
#include <stdlib.h>
#include "cirListDeque.h"

int main (int argc, const char * argv[])
{
	struct cirListDeque testDeque; 		/* non-sentinel list */
	TYPE val1 = 1.0;
	TYPE val2 = 2.0;
	TYPE val3 = 3.0;

	printf("** Testing Deque ADT based on Circularly-Doubly-Linked List **\n");
	/* initialize the deque */
	initCirListDeque(&testDeque);
	/* add val2 to the back */
	addBackCirListDeque(&testDeque, val2);
	/* add val3 to the back, val2 becomes the front */
	addBackCirListDeque(&testDeque, val3);
	/* add val1 to the front */
	addFrontCirListDeque(&testDeque, val1);

	/* it should print out 1.0  2.0  3.0 */
	printCirListDeque(&testDeque);
	reverseCirListDeque(&testDeque);
	/* it should print out 3.0  2.0  1.0 */
	printCirListDeque(&testDeque);

	/* it should print out front: 3.0; back: 1.0 */
	printf("front: %d; back: %d\n\n",   frontCirListDeque(&testDeque),
                                        backCirListDeque(&testDeque));
	/* remove the back of the deque */
	removeBackCirListDeque(&testDeque);
	/* it should print out front: 3.0; back: 2.0 */
	printf("front: %d; back: %d\n\n",   frontCirListDeque(&testDeque),
                                        backCirListDeque(&testDeque));
	/* remove the front of the deque */
	removeFrontCirListDeque(&testDeque);
	/* it should print out front: 2.0; back: 2.0 */
	printf("front: %d; back: %d\n\n",   frontCirListDeque(&testDeque),
                                        backCirListDeque(&testDeque));
	/*freeCirListDeque(&testDeque);*/
	return EXIT_SUCCESS;
}
