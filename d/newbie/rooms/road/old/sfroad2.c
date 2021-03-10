//efroad4.c - mobs added by Styx

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
You are on a narrow dirt trail between the forest to the north
and the road to the south.  You are not quite on the edge of the
forest here.  The trees and plants are gathered close around you.
JAVAMAKER
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind in the trees.");
   set_exits(([
      "south":ROAD"sfroad1",
      "north":FOREST"forest72",
      "northeast":FOREST"forest73",
   ]));
   set_items(([
       "trail":"The dirt is hard-packed beneath your feet.",
       ({"trees","plants"}):"The trees and plants are plentiful here, very lush and green.",
   ]));
}

void init() {
   ::init();
   if(!userp(TP))  return;
   if( (TP->query_level() > 2) && !wizardp(TP) )
      if ( (random(9) < 2 ) && (!present("orc")) ) {
    	switch(random(5)) {
    	case 0:
    		tell_room(TO, "%^ORANGE%^A large menacing orc shuffles out from behind some bushes and glares threateningly.");
   	   	new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
   	   	break;
    	case 1:
    		tell_room(TO, "%^BOLD%^A couple of smelly vicious-looking orcs pop out from behind some trees.");
    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		break;
    	case 2:
		tell_room(TO, "%^BOLD%^Three large orcs jump out in your path!");
    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		break;
	case 3:
		tell_room(TO, "%^GREEN%^You hear some rustling in the bushes as you pass by but don't see anything.");
	case 4:
    		tell_room(TO, "%^RED%^An arrow whizzes past your ear and you hear a hasty retreat through the bushes when it misses.");
	}
   }
}	
