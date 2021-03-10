#include <std.h>
#include "../theater.h"
inherit ORCH;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"dso4",
			 "south" : ROOMDIR"dso1",
		    ]));
}