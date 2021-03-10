#include <std.h>
#include "../theater.h"
inherit ORCH;
	void create(){ 
	::create();
	set_exits(([ "east" : ROOMDIR"dso3",
			 "south" : ROOMDIR"dso5",
		    ]));
}