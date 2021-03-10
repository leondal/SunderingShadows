#include <std.h>
#include "../theater.h"
inherit COST;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cost1",
			 "east" : ROOMDIR"cost4",
			]));
}