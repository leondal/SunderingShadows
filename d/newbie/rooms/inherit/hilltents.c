//hilltents.c to inherit to the hill rooms for tents

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",0);
   set_short("Rolling hills");
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
   set_long(
@JAVAMAKER
You are walking through some rolling hills. Small plants
cover the hills surrounding you. The hills flatten out some
to the west. There are tracks in the dirt and quite a few 
small tents scattered around the hills.
JAVAMAKER
   );
   set_exits(([
      "north":HILL"hill14",
   ]));
   if (!random(4) && (!objectp(present("tent"))) ) {
  	   new("/d/newbie/rooms/inherit/tentob")->move(TO);
    	switch(random(5)) {
    		case 0: 
		   		tell_room(TO, "A dwarf drags in a large chest and begins unpacking it."             "\nHe quickly sets up a tent and drags the chest inside.\n");
		   		new(HILL"mon/dwarf1")->move(TO);
		   		if (objectp(find_object(HILL"mon/dratharm"))) break;
   			find_object_or_load(HILL"mon/dratharm")->move(TO);
  		  		break;
   		case 1:
    		   tell_room(TO, "%^BOLD%^%^GREEN%^A pair of halflings wander in carrying a chest.  They unpack and set up a tent.\n");
   			new(HILL"mon/halflingf")->move(TO);
		   		new(HILL"mon/halfling")->move(TO);
  		  		break;
    		case 2:
    		   tell_room(TO, "%^BOLD%^%^GREEN%^Two tired looking gnomes shuffle into the room dragging a heavy-looking chest.\nThey pull out a tent and set it up.\n");
   			new(HILL"mon/gnometentf")->move(TO);
		   		new(HILL"mon/gnometent")->move(TO);
  		  		break;
			case 3:
				tell_room(TO, "%^BOLD%^%^GREEN%^A perky gnome female wanders in whistling a merry tune while she goes about setting up a tent.\n");
   			new(HILL"mon/gnometentf")->move(TO);
   			break;
   		case 4:	
   			tell_room(TO, "%^BOLD%^%^GREEN%^A cheery halfling sets up a tent and ducks inside.\n");
		   		new(HILL"mon/halfling")->move(TO);
  		  		break;
			}
		}
}

//moved the tent creations up into create to try to fix the rooms from losing
//their exits on occassion even though we don't really know why they do yet.
//Styx 8/7/01

void reset() {
    ::reset();
   if(!objectp(present("tent"))) remove_exit("tent");
}