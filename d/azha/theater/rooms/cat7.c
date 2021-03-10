#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"cat8",
			 "east" : ROOMDIR"cat4",
		    ]));
}