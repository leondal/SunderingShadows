#include <std.h>
#include "../theater.h"
inherit ORCH;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"dso4",
			 "south" : ROOMDIR"dso6",
			 "east" : ROOMDIR"dso1",
		    ]));
}