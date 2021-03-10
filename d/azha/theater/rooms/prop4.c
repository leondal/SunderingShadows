#include <std.h>
#include "../theater.h"
inherit PROP;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"prop5",
			 "south" : ROOMDIR"prop2",
			]));
}