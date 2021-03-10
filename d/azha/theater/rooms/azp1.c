#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"cal5",
			 "east" : ROOMDIR"azp2",
			]));
}