#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){
	::create();
	set_exits(([ "north" : ROOMDIR"cat8",
			 "east" : ROOMDIR"cat6",
		    ]));
}
