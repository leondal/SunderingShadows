#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cellar5",
			 "east" : ROOMDIR"cellar3",
			]));
}