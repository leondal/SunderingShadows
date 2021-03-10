#include <std.h>
#include "../theater.h"
inherit UNDER;
	void create(){ 
	::create();
	set_exits(([ "east" : ROOMDIR"prop1",
			 "south" : ROOMDIR"under4",
			]));
}