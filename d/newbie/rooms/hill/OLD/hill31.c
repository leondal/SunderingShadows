//hill31.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);   
   set_short("A larger hill");
   set_long(
@JAVAMAKER
You are walking through some rolling hills. Small plants cover the hills surrounding you. The hills flatten out some to the west. The tracks in the dirt are different here and you also see what might be blood stains. To the east and southeast, the hills appear uninhabited.
JAVAMAKER
   );
   set_smell("default","You smell the plants surrounding you.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tents":"These look like temporary storage or sleeping places.",
      "tracks":"The tracks are of something larger heading northeast here.",
   ]));
   set_exits(([
      "south":HILL"hill32",
      "northwest":HILL"hill26",
      "west":HILL"hill27",
      "southwest":HILL"hill28",
      "northeast":HILL"hill31a",
   ]));
   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}

void reset() {
	::reset();
	if ( !random(4) && (!present("hobgoblin")) ) {	
    	switch(random(4)) {
    		case 0: 
   		    	new(HILL"mon/hobgob")->move(TO);
   		    	break;
   		case 1:
    		   	new(HILL"mon/hobgobfe")->move(TO);
			break;
    		case 2:	
    			new(HILL"mon/hobgob")->move(TO);
			new(HILL"mon/hobgobf2")->move(TO);
			break;
		case 3:
    			new(HILL"mon/hobgobf")->move(TO);
    			new(HILL"mon/hobgobf2")->move(TO);
			break;			
		}
	}
}
