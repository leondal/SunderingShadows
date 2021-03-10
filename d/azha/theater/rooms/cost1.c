#include <std.h>
#include "../theater.h"
inherit COST;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"under7",
			 "east" : ROOMDIR"cost2",
			 "south" : ROOMDIR"cost3",
			]));
}