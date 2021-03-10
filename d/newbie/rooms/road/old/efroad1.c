//efroad1.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_short("A dirt trail");
   set_long(
@JAVAMAKER
You are on a narrow dirt trail between the forest to the southwest
and the road to the northeast. You are on the edge of the forest here,
and the trees and plants are scattered. Just to the northeast you see
the wide gravel road meet this path.
JAVAMAKER
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind in the trees.");
   set_exits(([
      "northeast":ROAD"road6",
      "west":ROAD"efroad2",
   ]));
   set_items(([
       "trail":"The dirt is hard-packed beneath your feet.",
       ({"trees","plants"}):"The trees and plants are sparse here, but very lush and green.",
   ]));
}

void init() {
    ::init();
	(userp(TP));
	if( (TP->query_level() > 2) && !wizardp(TP) )
	if ( (random(4) < 1 ) && (!present("orc")) ) {
    	switch(random(3)) {
    		case 0:
    			write("A large menacing orc shuffles out from behind some bushes.");
    			say("A large menacing orc shuffles out from behind some bushes.");
   	    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
   	    		break;
   	    	case 1:
    			write("A pair of smelly vicious-looking orcs shuffle out from behind some trees.");
    			say("A pair of smelly vicious-looking orcs shuffle out from behind some trees.");
    	   		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
				new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
				break;
    		case 2:
    			write("Three large orcs jump out in your path brandishing their weapons!");
				say("Three large orcs jump out in your path brandishing their weapons!");
    			new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
				new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
				new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
				break;
			}
	}
}	
