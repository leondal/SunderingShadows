#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "southwest" : ROOMDIR"azp5",
			 "east" : ROOMDIR"azp7",
			]));
}