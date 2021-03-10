#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"cat4",
			 "south" : ROOMDIR"cat2",
			 "down" : ROOMDIR"stairs2",
		    ]));
}