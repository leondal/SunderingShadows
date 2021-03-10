/*
   queue.c: simple fixed-size queue (FIFO) in LPC 3.0
    -- by Truilkan@TMI - 92/01/31
*/

private mixed *queue;
private int hptr, tptr, size, primed;
private int count;

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
   queue[tptr] = elt;  /* post-increment */
   tptr = (tptr + 1) % size;
   return 0;
}

void alloc(int s)
{
   count = 0;
   hptr = 0;
   tptr = 0;
   size = s;
   queue = allocate(size);
}

mixed access(int i)
{
   int j;

   if (i < 0)
      return 0;
   j = (hptr + i) % size;
   if (j >= 0 && j < size)
      return queue[j];
   else
      return 0;
}

void pad_field(int count)
{
   if (count < 10000)
      write(" ");
   if (count < 1000)
      write(" ");
   if (count < 100)
      write(" ");
   if (count < 10)
      write(" ");
}

void print(int start)
{
   int j, label;

   j = hptr;
   label = start;
   do {
      pad_field(label);
      write(label + "  " + queue[j] + "\n");
      j = (j + 1) % size;
      label++;
   } while (j != tptr);
}

void remove()
{
   destruct(this_object());
}
