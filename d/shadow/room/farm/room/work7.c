#include <std.h>
#include "../farm.h"
inherit WORKROOM;
	void create(){ 
	::create();
	set_exits(([ "east" : ROOMDIR"work6",
			 "down" : ROOMDIR"cellar1",
			]));
}