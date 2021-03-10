/*
  SET_ADT: LPC Set ADT - inherits from ILIST_ADT

  author: Truilkan@TMI, 05/26/91 (modified for TMI - 92/02/01)

*/

#include "adt_defs.h"

inherit ILIST_ADT;

mixed member(mixed arg)
{
	mixed *cur;
	mixed val;

	cur = query_head();
	while (cur != NULL) {
		val = value(cur);
		if ((val == arg) || (objectp(val) &&
				((int)val->id(arg) || (int)val->key(arg))))
			return val;
		else
			cur = next(cur);
	}
	return 0;
}

/* insert: don't allow duplicates */

mixed *insert(object obj)
{
	if (!member(obj))
		return ::insert(obj);
	else
		return NULL;
}

string query_short()
{
	return "a set object";
}

void create()
{
	ilist::create();
}
