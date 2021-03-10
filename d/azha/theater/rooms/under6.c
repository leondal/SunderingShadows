#include <std.h>
#include "../theater.h"
inherit UNDER;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"under1",
			 "south" : ROOMDIR"under7",
			]));
}