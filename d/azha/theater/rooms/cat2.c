#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cat1",
			 "south" : ROOMDIR"cat3",
			 "west" : ROOMDIR"cat5",
		    ]));
}