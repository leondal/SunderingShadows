/*
  -- ported to 3.0 by Truilkan@TMI - 92/01/30
*/

/*******************************************************************
Description:

   Simple doubly linked list ADT written as an LPC object:

   This object may be used as is or as the basis for other abstract data
   types such as a stack, a set, or an orderd list.  If you plan to use
   this object as is, then cloning this file [clone_object(THISFILE)]
   is the preferred means of getting a copy.  If you plan to use this
   object as the basis for another ADT, then inheritance is the preferred
   means of obtaining a copy [inherit THISFILE;].

Implementation:

   Each node of the list is implemented as a two-tuple obtained via the
   allocate(2) call.  The first element of each tuple is an object.
   The second element of each tuple is in turn another two-tuple
   (representing the next element in the list).  C programmers will
   find that LPC arrays (returned by the allocate() call) provide the
   equivalent functionality of the C structure (or Pascal record) since
   LPC arrays do not require each element of an array to be of the same type.

author: Truilkan@Babylon - May 26, 1991
********************************************************************/

#include "adt_defs.h"

private mixed *theHead, *theTail;

protected mixed *set_head(mixed *arg)
{
	return (theHead = arg);
}

protected mixed *set_tail(mixed *arg)
{
	return (theTail = arg);
}

protected void set_prev(mixed *arg, mixed *before)
{
	if (arg != NULL)
		arg[2] = before;
}

protected void set_next(mixed *arg, mixed *after)
{
	if (arg != NULL)
		arg[1] = after;
}

mixed *query_head()
{
	return theHead;
}

mixed *query_tail()
{
	return theTail;
}

protected mixed *new_elt(mixed thisObj, mixed *nextObj, mixed *prevObj)
{
	return ({ thisObj, nextObj, prevObj });
}

mixed value(mixed *arg)
{
	if (arg)
		return arg[0];
	else
		return 0;
}

mixed *next(mixed *arg)
{
	if (arg != NULL)
		return arg[1];
	else
		return NULL;
}

mixed *prev(mixed *arg)
{
	if (arg)
		return arg[2];
	else
		return NULL;
}

/* insert: Here I insert at the head of the list so that this
   object might form the basis of a stack ADT.  Note that this
   object might also form the basis of an ordered list if insert()
   is redefined appropriately in an object inheriting this one. */

mixed *insert(mixed obj)
{
	mixed *ohead, *nhead;

	ohead = query_head();
	set_prev(ohead,nhead = set_head(new_elt(obj,query_head(),NULL)));
	return nhead;
}

/* note that delete does not (and can not) explicitly free any space
   because LPC does its own garbage collection */

mixed delete(mixed obj)
{
	mixed *cur, *before, *after;

	if (obj == value(query_head())) {
		set_head(next(query_head()));
		set_prev(query_head(),NULL);
		return obj;
	}
	cur = next(before = query_head());
	while (cur != NULL) {
		after = next(cur);
		if (obj == value(cur)) {
			set_next(before,after);
			set_prev(after,before);
			return obj;
		}
		before = cur;
		cur = after;
	}
	return NULL;
}

int empty()
{
	return query_head() == NULL;
}

string query_short()
{
	return "a list_adt object";
}

string query_long(string arg)
{
	return "This is a " + arg + ".  There really isn't much that you can\n" +
	 "do with it from an interactive environment.  It is meant\n" +
	 "to be accessed via the clone_object() or inherit LPC calls.\n";
}

void print()
{
	mixed cur;
    mixed val;

	cur = query_head();
	while (cur != NULL) {
		val = value(cur);
		if (objectp(val) && val->query_short())
			write("object: " + val->query_short() + "\n");
		else
			write(val + "\n");
		cur = next(cur);
	}
}

int id(string arg)
{
	return arg == "list";
}

void create()
{
	set_head(NULL);
	set_tail(NULL);
}
