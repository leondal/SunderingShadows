#include <std.h>
#include "../theater.h"
inherit ORCH;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"dso5",
			 "north" : ROOMDIR"dso3",
			 "south" : ROOMDIR"dso2",
			 "foyer" : ROOMDIR"theater2",
		    ]));
}