//road38.c - mobs added by Styx

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
    set_short("A wide gravel trail");
    set_long(
@NEWBIE
You are on a wide trail passing across mostly open land. You can
see a forest off in the distance to the northeast.  The gravel trail
is thin over the hard-packed dirt.  A small dirt path leads to the
northeast, into the forest.  To the northwest, you can see what
appears to be a town.
NEWBIE
    );
    set_smell("default","You smell the fresh air of the open land.");
    set_listen("default","You hear the sound of the wind rushing across the open land.");
    set_exits(([
       "west":ROAD"road39",
       "northeast":ROAD"wfroad1",
       "southeast":ROAD"road37",
   ]));
}

void init() {
   ::init();
   if(!userp(TP))  return;
   if( (TP->query_level() > 3) && !wizardp(TP) )
      if ( (random(9) < 2 ) && (!present("orc")) ) {
    	switch(random(5)) {
    	case 0:
    		tell_room(TO, "%^BOLD%^A large menacing orc shuffles in from the other direction.");
   	   	new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
   	   	break;
    	case 1:
    		tell_room(TO, "%^ORANGE%^Two vicious-looking orcs step in your path from the fork.");
    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		break;
    	case 2:
    		tell_room(TO, "%^MAGENTA%^Three vicious orcs step in front of you brandishing weapons!");
    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		break;
	case 3:
		tell_room(TO, "%^BOLD%^%^RED%^You notice fresh blood in the gravel.");
	case 4:
    		tell_room(TO, "%^RED%^An arrow whizzes past your ear.  You hear a quick scuffling retreat in the gravel down the other fork as it misses.");
	}
   }
}	



