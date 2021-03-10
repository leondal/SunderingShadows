#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"azp3",
	             "northeast" : ROOMDIR"azp5",
                     "ruins" : "/d/magic/temples/beshaba"
			]));
}
