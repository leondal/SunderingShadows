#include <std.h>
#include "../theater.h"
inherit ORCH;
	void create(){ 
	::create();
	set_exits(([ "east" : ROOMDIR"dso2",
			 "north" : ROOMDIR"dso5",
		    ]));
}