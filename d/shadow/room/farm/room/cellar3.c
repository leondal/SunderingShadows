#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cellar2",
			 "west" : ROOMDIR"cellar4",
			 "east" : ROOMDIR"cellar6",
			]));
}