#include <std.h>
#include "../theater.h"
inherit AZP;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"azp6",
			 "north" : ROOMDIR"azp8",
                         "east" : "/d/avatars/nienne/dragonlair/village",
                        ]));
}
