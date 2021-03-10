#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "southwest" : ROOMDIR"azp4",
			 "northeast" : ROOMDIR"azp6",
			]));
}