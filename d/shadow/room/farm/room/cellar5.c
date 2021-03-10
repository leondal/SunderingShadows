#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"cellar4",
			]));
}