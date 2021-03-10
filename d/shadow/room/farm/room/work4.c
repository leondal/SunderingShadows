#include <std.h>
#include "../farm.h"
inherit WORKROOM;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"work3",
			 "east" : ROOMDIR"work5",
			]));
}