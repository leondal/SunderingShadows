#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "north" : ROOMDIR"cellar7",
			 "west" : ROOMDIR"cellar3",
			]));
}