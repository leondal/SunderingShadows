
#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
	set_property("indoors",0);
	set_property("light",1);
    set_long(::query_long()+"Massive pillars have been carved directly from the cliff wall here! Far above you, a large slab has been placed across them. To the north, a channel cuts through the mountain. It makes up the inside of a temple carved from the very rock around you! Armored guardians pace the area. Two watch you from the slab atop the pillars!");
       set_exits(([
          "north":"/d/attaya/cliff12",
         "east":"/d/attaya/cliff10"
]));
}

void reset(){
	int num, i;
	::reset();
	if(!present("phalanx")){
		for(i=0;i<2;i++)
			new("/d/attaya/mon/phalanx")->move(TO);
	}
	
}

