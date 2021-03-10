#include <std.h>
#include "../theater.h"
inherit PROP;
	void create(){ 
	::create();
	set_exits(([ "crate" : ROOMDIR"prop2",
			]));
}
void reset()
{
    	::reset();
    	if(!present("ranger")) 
{
	new(MOB"marion_ranger")->move(TO) ;
    	return;
}
}