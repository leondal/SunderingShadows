/*
   cstack.c: simple fixed-size circular stack in LPC 3.0
    -- by Truilkan@TMI - 92/03/11
*/

nosave mixed *queue;
nosave int hptr, tptr, size, primed;
nosave int count;

mixed *query_queue()
{
	return queue;
}

mixed dequeue()
{
   int h;

   if (!count)
      return -1;
   count--;
   h = hptr;
   hptr = (hptr + 1) % size;
   return queue[h];          /* pre-increment */
}

int enqueue(mixed elt)
{
   if (count++ == size)
      return -1;
   if(!pointerp(queue)) queue = allocate(10);
   queue[tptr] = elt;  /* post-increment */
   //tptr = (tptr + 1) % size;
   return 0;
}

mixed pop()
{
	int h;

	if (!count)
		return -1;
	count--;
	h = hptr;
	hptr = (hptr + size - 1) % size;
	return queue[h];
}

void alloc(int s)
{
   count = 0;
   hptr = 0;
   tptr = 0;
   size = s;
   queue = allocate(size);
}

void remove()
{
   destruct(this_object());
}
