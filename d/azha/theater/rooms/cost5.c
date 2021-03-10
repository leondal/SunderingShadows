#include <std.h>
#include "../theater.h"
inherit COST;
	void create(){ 
	::create();

	set_exits(([ "north" : ROOMDIR"cost4",
			]));
}
void reset()
{
    	::reset();
    	if(!present("mage")) 
{
	new(MOB"marion_mage")->move(TO) ;
    	return;
}
}