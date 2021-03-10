#include <std.h>
#include "../theater.h"
inherit COST;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"cost1",
			 "south" : ROOMDIR"cost4",
			]));
}