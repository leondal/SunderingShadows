#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"azp2",
			 "north" : ROOMDIR"azp4",
			]));
}