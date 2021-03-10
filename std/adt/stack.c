/*
   stack.c: simple fixed-size stack (FILO) in LPC 3.0
    -- by Truilkan@TMI - 92/01/31
*/

private mixed *stack;
private int sptr, size;

void empty()
{
	sptr = 0;
}

mixed pop()
{
	if (sptr < 1)
		return -1;
	return stack[--sptr]; /* predecrement */
}

int push(mixed elt)
{
	if (sptr >= size)
		return -1;
	stack[sptr++] = elt;  /* post increment */
	return 0;
}

void alloc(int s)
{
	sptr = 0;
	size = s;
	stack = allocate(size);
}

void remove()
{
    destruct(this_object());
}
