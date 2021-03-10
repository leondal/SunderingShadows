#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel dead ends "+
    "here and your only option to trek back eastward.%^RESET%^");
    set_exits(([
        "east" : FTUN_ROOMS"firetunnels21",
    ] ));
}

void reset() 
{
  	int x;
    	object imp;
    	::reset();
  
    	if(!present("fire elemental 2")) 
	{
      	x = 2 + random(2);
        	while(x) 
		{
            	imp = new(DEKU_MON"fire_elemental");
            	imp->set_speed(0);
            	imp->set_moving(0);
            	imp->move(TO);
            	x--;
        	}
    	}
	if(!present("fire elemental king")) 
	{
      	new(DEKU_MON"fire_elemental_king")->move(TO);
    	}
}
