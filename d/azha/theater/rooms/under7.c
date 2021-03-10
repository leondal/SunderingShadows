#include <std.h>
#include "../theater.h"
inherit UNDER;
	void create(){
	::create();
	set_exits(([ "east" : ROOMDIR"cost1",
			 "north" : ROOMDIR"under6",
			]));
}
