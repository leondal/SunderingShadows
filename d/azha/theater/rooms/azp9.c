#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"azp8",
			 "north" : "/d/tharis/road/wroad13",
			]));
}