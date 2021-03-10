#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cellar1",
			 "south" : ROOMDIR"cellar3",
			]));
}