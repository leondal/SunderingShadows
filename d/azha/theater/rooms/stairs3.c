#include <std.h>
#include "../theater.h"
inherit STAIRS;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"mezz2",
			 "stairs" : ROOMDIR"stairs4",
		    ]));
}