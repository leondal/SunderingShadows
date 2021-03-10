#include <std.h>
#include "../farm.h"
inherit WORKROOM;
	void create(){ 
	::create();
	set_exits(([ "up" : ROOMDIR"bedroom",
			 "southwest" : ROOMDIR"work2",
			]));
}