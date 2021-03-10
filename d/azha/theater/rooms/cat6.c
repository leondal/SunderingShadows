#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){
	::create();
	set_exits(([ "east" : ROOMDIR"cat3",
			 "north" : ROOMDIR"cat5",
			 "west" : ROOMDIR"cat9",
		    ]));
}
