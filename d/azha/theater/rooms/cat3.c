#include <std.h>
#include "../theater.h"
inherit CAT;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cat2",
			 "west" : ROOMDIR"cat6",
		    ]));
}