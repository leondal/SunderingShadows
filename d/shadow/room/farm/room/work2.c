#include <std.h>
#include "../farm.h"
inherit WORKROOM;
	void create(){ 
	::create();
	set_exits(([ "northeast" : ROOMDIR"work1",
			 "south" : ROOMDIR"work3",
			]));
}