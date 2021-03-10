#include <std.h>
#include "../theater.h"
inherit STAIRS;
	void create(){ 
	::create();
	set_exits(([ "foyer" : ROOMDIR"theater2",
			 "stairs" : ROOMDIR"stairs2",
		    ]));
}