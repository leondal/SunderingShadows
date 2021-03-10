//hill32.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);   
   set_short("Rolling hills");
   set_long(
@JAVAMAKER
You are walking through some rolling hills. Small plants cover the hills surrounding you. The hills flatten out some to the west. There are tracks in the dirt and some of them here seem larger than in the rest of the area.  To the east, the hills appear uninhabited.
JAVAMAKER
   );
   set_smell("default","You smell the plants surrounding you.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tracks":"The tracks look humanoid and are sometimes smoothed by something being drug along.  This area is definitely more heavily traveled.",
	"dirt":"Here and there the dirt is darker from what might be bloodstains.",	
]));

   set_exits(([
      "north":HILL"hill31",
      "south":HILL"hill33",
      "northwest":HILL"hill27",
      "west":HILL"hill28",
      "southwest":HILL"hill29",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}

void reset() {
	::reset();
	if ( (random(7) < 2 ) && (!present("hobgoblin")) ) {	
    	switch(random(4)) {
	   case 0: 
   	    	new(HILL"mon/hobgob")->move(TO);
   	    	break;
   	   case 1:
    	  	new(HILL"mon/hobgobf2")->move(TO);
		break;
    	   case 2:	
    		new(HILL"mon/hobgob")->move(TO);
		new(HILL"mon/hobgobf2")->move(TO);
		break;
	   case 3:
    	 	new(HILL"mon/hobgobf")->move(TO);
    		new(HILL"mon/hobgobfe")->move(TO);
		new(HILL"mon/hobgob")->move(TO);
		break;			
	 }
    }
}
