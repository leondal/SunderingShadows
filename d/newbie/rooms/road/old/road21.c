//road21.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
   set_short("A wide gravel trail");
   set_long(
@NEWBIE
You are on a wide trail passing through some small hills.
You can see a forest off in the distance to the north.
The gravel trail is thin over the hard-packed dirt.
NEWBIE
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_exits(([
      "southwest":ROAD"road22",
      "east":ROAD"road20",
   ]));
}

void init() {
   ::init();
   if(!userp(TP))  return;
   if( (TP->query_level() > 3) && !wizardp(TP) )
   if ( !random(5)  && !present("orc") ) {
      switch(random(5)) {
    	case 0:
    		tell_room(TO, "%^YELLOW%^You meet two menacing orcs coming around the bend.");
   	   	new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
   	   	new("/d/newbie/rooms/forest/mon/orc")->move(TO);
   	   	break;
    	case 1:
    		tell_room(TO, "%^BOLD%^A small group of smelly vicious-looking orcs shuffle in from around the bend.");
    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		new("/d/newbie/rooms/forest/mon/orc")->move(TO);
		break;
    	case 2:
    		tell_room(TO, "%^ORANGE%^A band of unfriendly orcs accosts you suddenly!");
    		new("/d/newbie/rooms/forest/mon/orcm")->move(TO);
		new("/d/newbie/rooms/forest/mon/orcf")->move(TO);
		new("/d/newbie/rooms/forest/mon/orc")->move(TO);
		new("/d/newbie/rooms/forest/mon/orc")->move(TO);
//		new("/d/newbie/rooms/forest/mon/orc")->move(TO);
		break;
	case 3:
		tell_room(TO, "%^BOLD%^You hear a commotion around the bend.");
	case 4:
		tell_room(TO, "%^RED%^You catch a glimpse of fresh blood in the gravel.");
	}
   }
}	




