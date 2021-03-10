#include <std.h>
#include "../farm.h"
inherit WORKROOM;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"work7",
			 "south" : ROOMDIR"work5",
			]));
}