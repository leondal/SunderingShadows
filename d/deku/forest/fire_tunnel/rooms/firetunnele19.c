#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel dead ends "+
    "here and your only option to trek back westward.%^RESET%^");
    set_exits(([
        "west" : FTUN_ROOMS"firetunnele18",
    ] ));
}

void reset() {
    	int x;
    	object imp;
    	::reset();
    	if(!present("hellhound")) 
	{
      	x = 2 + random(2);
        	while(x) 
		{
            	imp = new(DEKU_MON"hellhound");
	            imp->set_speed(0);
      	      imp->set_moving(0);
            	imp->move(TO);
	            x--;
      	}
    	}
	if(!present("hound keeper")) 
	{
      	new(DEKU_MON"hound_keeper")->move(TO);
    	}
}
