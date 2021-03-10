#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cat4",
			 "south" : ROOMDIR"cat6",
			 "west" : ROOMDIR"cat8",
			 "east" : ROOMDIR"cat2",
		    ]));
}