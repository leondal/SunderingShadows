#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel dead ends "+
    "here and your only option to trek back northward.%^RESET%^");
    set_exits(([
        "northeast" : FTUN_ROOMS"firetunnelw21",
    ] ));
}

void reset() {
	int x;
    	object imp;
    	::reset();

    	if(!present("hellfire golem 2")) 
	{
      	x = 2 + random(2);
        	while(x) 
		{
            	imp = new(DEKU_MON"hellfire_golem");
            	imp->set_speed(0);
            	imp->set_moving(0);
            	imp->move(TO);
            	x--;
        	}
    	}
	if(!present("golem master")) 
	{
      	new(DEKU_MON"golem_master")->move(TO);
    	}
}
