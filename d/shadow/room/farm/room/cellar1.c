#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "up" : ROOMDIR"work7",
			 "south" : ROOMDIR"cellar2",
			]));
}