#include <std.h>
#include "../theater.h"
inherit PROP;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"under5",
			 "east" : ROOMDIR"prop2",
			 "north" : ROOMDIR"prop5",
			]));
}