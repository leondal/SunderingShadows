#include <std.h>
#include "../theater.h"
inherit UNDER;
	void create(){
	::create();
	set_exits(([ "north" : ROOMDIR"under5",
			 "south" : ROOMDIR"under1",
			]));
}
