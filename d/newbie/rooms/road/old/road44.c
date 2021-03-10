//road44.c Road from Offestry west gate to ruins

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
You are on a wide trail passing across mostly open land.  You can
see a forest off in the distance to the southeast.  The gravel trail
is thin over the hard-packed dirt.  To the south and west you can see 
the ruins of a small town.
NEWBIE
    );
    set_smell("default","You smell the fresh air of the open land.");
    set_listen("default","You hear the sound of the wind rushing across the open land.");
    set_exits(([
       "south":N_RUINS"road9",
       "east":ROAD"road45",
   ]));
}

void reset() {
	::reset();
   if( !present("bat") && !present("snake") && (query_night() == 1) && (random(5) < 3) ) {
	    switch(random(3)) {
			case 0:       
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				break;
			case 1:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				break;
			case 2:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				break;				
		}
	}
	if( !present("snake") && !present("bat") && (query_night() == 0) && (random(5) < 3) ) {
	    switch(random(3)) {
			case 0:       
				new("/d/newbie/mon/rat")->move(TO);
				break;
			case 1:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 2:
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				break;			
		}
	}
}
