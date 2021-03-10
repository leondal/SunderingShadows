#include <std.h>
#include "../theater.h"
inherit ORCH;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"dso6",
			 "north" : ROOMDIR"dso1",
		    ]));
}