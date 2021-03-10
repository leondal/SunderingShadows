#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"azp7",
			 "north" : ROOMDIR"azp9",
			]));
}