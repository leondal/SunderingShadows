/*
   semaphore: an implementation of semaphores in LPC

   by Truilkan@TMI -- 92/01/30

   see page 88 of _Operating System Concepts_ by Silberschatz and Peterson.
   ISBN 0-201-18760-4
*/

#define IDLE    0
#define WANT_IN 1
#define IN_CS   2

#define VALUE  0
#define MAX    1
#define QUEUE  2
#define STACK  3
#define SPIN   4
#define FLAG   5
#define TURN   6
#define N      7

#define TRUE  1 
#define FALSE 0

#if 0
#define DEBUG(x) tell_object(find_player("truilkan"),x)
#else
#define DEBUG(x)
#endif

/*
   MAX_WAITING: default maximum number expected to ever hit critical
   section entrance at same time
*/
#define MAX_WAITING 25

#include "adt_defs.h"

/*
   preamble: this function could be optimized by changing it to
    only examine those flag elements that are currently in use
    (corresponds to the indices that have been popped off the tag stack.
    Could keep track of these indices with another stack.
*/

private int preamble(mixed *sem)
{
	int i, j, n, turn;
	int *flag;

	flag = sem[FLAG];
	n = sem[N];
	turn = sem[TURN];
	i = (int)sem[STACK]->pop(); /* get a tag */
	if (i < 0)
		throw("semaphore: stack underflow\n");
	do {
		flag[i] = WANT_IN;
		j = turn;
		while (j != i) {
			if (flag[j] != IDLE)
				j = turn;
			else
				j = (j + 1) % n;
		}
		flag[i] = IN_CS;
		j = 0;
		while ((j < n) && (j == i || (flag[j] != IN_CS))) {
			j++;
		}
	} while ((j != n) || ((turn != i) && (flag[turn] != IDLE)));
	sem[TURN] = i;
	return i;
}

private void postamble(mixed *sem, int i)
{
	int j, turn, n;
	int *flag;

	flag = sem[FLAG];
	n = sem[N];
	turn = sem[TURN];
	j = (turn + 1) % n;
	while (flag[j] == IDLE)
		j = (j + 1) % n;
	flag[i] = IDLE;
	sem[TURN] = j;
	sem[STACK]->push(i);
}

/*
   spin_block: expensive way to block a process, no?  Hopefully, the
   critical section will be short and this code won't be executed for
   very long.  Please let me know if you have a better way to suspend
   a process (Truilkan@TMI).
*/

void spin_block(mixed *sem, int i)
{
	int *spin;

	DEBUG("in spin_block\n");
	spin = sem[SPIN];
	DEBUG("spinning\n");
	while (spin[i]) /* empty loop waiting for spin[i] to be changed non-zero */
		;
	if ((int)sem[STACK]->push(i) < 0) /* reuse the tag */
		throw("semaphore: stack overflow\n");
}

void wait(mixed *sem)
{
	int i, id, *spin, do_throw;

	DEBUG("wait: before preamble\n");
	i = preamble(sem);
	DEBUG("wait: after preamble\n");
	do_throw = 0;

	DEBUG("wait: before spin = sem[SPIN]\n");
	spin = sem[SPIN];
	DEBUG("wait: before if sem[VALUE]-- check\n");
	DEBUG("wait: sem[VALUE] == " + sem[VALUE] + "\n");
	if (--sem[VALUE] < 0) {
		DEBUG("wait: before enqueue\n");
		if ((int)sem[QUEUE]->enqueue(i) != -1) {
			DEBUG("wait: spin[i] = TRUE\n");
			spin[i] = TRUE;
		}
		else
			do_throw = 1;
	}
	else
		spin[i] = FALSE;

	DEBUG("wait: before postamble\n");
	postamble(sem,i);
	DEBUG("wait: after postamble\n");

	if (do_throw) /* should do this AFTER postamble */
		throw("semaphore: blocked_queue is full\n");
	if (spin[i])
		spin_block(sem,i); /* must be AFTER postamble */
}

void wakeup(int *spin, int id)
{
	spin[id] = FALSE;
}

void signal(mixed *sem)
{
	int i, id;
	
	i = preamble(sem);

	if (++sem[VALUE] <= 0) {
		id = (int)sem[QUEUE]->dequeue();
		wakeup(sem[SPIN],id);
	}

	postamble(sem,i);
}

/*
   alloc: allocate semaphore

   returns a 8-tuple:
({rem_amt_allowed, max_amt_allowed, blocked_queue, tag_stack, spin_vector,
  flag, turn, n})
*/

varargs mixed *alloc(int max_in_cs, int max_waiting)
{
	int j, q_size, n;
	object queue, stack;
	int *flag;

	/*
     default queue size is twice the max number allowed in critical section
     at one time.
	*/
	q_size = (max_waiting) ? max_waiting : MAX_WAITING;
	n = q_size;
	flag = allocate(q_size);
	for (j = 0; j < q_size; j++) {
		flag[j] = IDLE;
	}
	seteuid(getuid(this_object()));
	(queue = clone_object(QUEUE_ADT))->alloc(q_size);
	(stack = clone_object(STACK_ADT))->alloc(q_size);
	for (j = 0; j < q_size; j++)
		stack->push(j);
	return ({ max_in_cs, max_in_cs, queue, stack, allocate(q_size), flag,0,n });
}
