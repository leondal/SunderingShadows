#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){
	::create();
	set_exits(([ "east" : ROOMDIR"cat1",
			 "south" : ROOMDIR"cat5",
			 "west" : ROOMDIR"cat7",
		    ]));
}
