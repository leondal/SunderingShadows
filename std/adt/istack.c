/* 
 stackobj.c: LPC Stack ADT - uses the list ADT

 author: Truilkan - 05/26/91

 Description:

    provides the following methods:

    push(obj), pop(), empty(), top()
*/

#include "definitions.h"

object list;

empty()
{
	return list->empty();
}

top()
{
	return list->value(list->first());
}

pop()
{
	return list->delete(list->first());
}

push(obj)
{
	return list->insert(obj);
}

reset(arg)
{
	if (!arg) {
		list = clone_object(LISTOBJFILE);
		return;
	}
}

id(str)
{
	return str == short();
}

short()
{
	return "stack_object";
}

long()
{
	list->long(short());
}

get()
{
	return 1;
}
