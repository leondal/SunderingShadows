#include <std.h>
#include "../theater.h"
inherit PROP;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"prop1",
			 "east" : ROOMDIR"prop4",
			]));
}