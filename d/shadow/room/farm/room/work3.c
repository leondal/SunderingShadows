#include <std.h>
#include "../farm.h"
inherit WORKROOM;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"work2",
			 "east" : ROOMDIR"work4",
			]));
}