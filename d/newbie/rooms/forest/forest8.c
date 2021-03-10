//forest8.c - bugbear cave entrance

#include "../../newbie.h"
#include "forest.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("%^BLUE%^Cave entrance%^RESET%^");
   set_terrain(NAT_CAVE);
   set_travel(FOOT_PATH);
   set_long(
@STYX
You've reached the entrance to a cave and it appears likely to have regular inhabitants.  %^BOLD%^Bones %^RESET%^lie in one corner behind a large %^BOLD%^%^BLACK%^kettle %^RESET%^that hangs over a fire near the entrance.  Short sections of tree trunks lie around the fire to sit on.
STYX
   );
   set_smell("default","You smell boiled meat and the smoke from the fire.");
   set_listen("default","You hear grunts and snarls from deeper in the cave.");
   set_items( ([ 
      "kettle": "%^BOLD%^%^BLACK%^A blackened iron kettle large enough to fit a goblin in seems to contain a stew of some sort.  The stew smells like its main ingredient is some sort of red meat.", 
     	({"pile", "bones"}):"%^BOLD%^%^WHITE%^The pile of bones appear to be mostly humanoid.  Many of them are smaller, however, and you might guess goblin or kobold.%^RESET%^", 
		({"tree", "trees", "sections", "trunk"}):"%^ORANGE%^Sections cut from tree trunks that were 2-3 ft. in diameter appear to be used for something to sit on.",
	]) );
   set_exits(([
      "west":FOREST"forest7",
      "south":FOREST"forest16",
      "southeast":FOREST"forest17",
   ]));
}

void reset() {
	::reset();
	if( (random(4) < 2) && (!present("bugbear")) ) {	
    	switch(random(4)) {
    		case 0: 
   		    	new(MONST"bugbearg")->move(TO);
   		    	break;
   		    case 1:
    		   	new(MONST"bugbearg")->move(TO);
    		   	new(MONST"bugbearg")->move(TO);
				break;
    		case 2:	
    			new(MONST"bugbearh")->move(TO);
				new(MONST"bugbearg")->move(TO);
				break;
			case 3:
    			new(MONST"bugbear")->move(TO);
				break;			
		}
	}
}
