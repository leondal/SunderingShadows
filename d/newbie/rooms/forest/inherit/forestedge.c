//forestedge.c - Thick forest

#include <std.h>
#include "/d/newbie/rooms/forest/forest.h"
#include "/d/newbie/newbie.h"
//#include "../../../newbie.h"
//#include "../forest.h"

inherit CROOM;
int make_mobs;

void create() {
   ::create();
   if(!random(3))  make_mobs = 1;
   set_repop(50); 
   set_property("light",1);
   set_property("no teleport",1);
   set_short("%^GREEN%^Thick forest%^RESET%^");
   set_terrain(HEAVY_FOREST);
   set_travel(GAME_TRACK);
   set_long( (: TO, "ldesc" :) );
   set_smell("default","The air is stale and musty.");
   set_listen("default","Now and then you hear an owl hoot from high in the trees.");
   set_items( ([ "bushes": "Long stretches of thorny bushes block passage for stretches here and there, almost like walls encircling the forest.", 
        "undergrowth":"%^BOLD%^%^GREEN%^The ivy and ferns are a paler green and stunted where they compete with the bushes.%^RESET%^", 
	({"vines", "trees"}):"%^ORANGE%^Many of the trees and bushes are entwined with heavy vines.%^RESET%^",
   ]) );
}

string ldesc(string str) {
   return("This area of the forest is becoming quite dense.  "
     "%^CYAN%^Long-needled pine trees %^RESET%^tower over other smaller "
     "evergreens and a few deciduous trees including oaks and sassafras.  The "
     "acidic soil from the decaying vegetable matter limits the undergrowth to "
     "a few varieties of ivy and ferns.  Pine needles and fallen leaves cushion "
     "your steps but %^ORANGE%^vines and thick bushes %^RESET%^block the way in "
     "various directions.");
}

void reset() {
   int active;
/* make_mobs in create sets whether a room will get mobs at all (for the 
     duration of the reboot) unless room dests & re-creates, which keeps 
     them from filling up eventually
   has_mobs() in CROOM checks for active mobs - if none (& supposed to be 
     per make_mobs) let the switch re-choose which ones to make next
   no_repop keeps the reset from respawning every time, also handled by CROOM
*/
   active = has_mobs();
   if(!active && make_mobs) {
      if(mons)  mons = ([]);      
      switch(random(4)) {
	case 0..1:  set_monsters( ({MONST"rattlesnake"}),({random(2)+1}));
		 break;
	case 2:  set_monsters( ({MONST"koboldf1"}),({2}));
		 break;
	case 3:  set_monsters( ({MONST"koboldf2", MONST"koboldf"}),({1, 2}));
		 break;
      }
   }

   ::reset();
/* changing to use CROOM controls so they don't fill up all the rooms over longer reboots
*Styx*  11/16/02
	if ( (random(9) < 2 ) && (!present("kobold")) && (!present("snake")) ) {	
    	switch(random(3)) {
    		case 0: 
   		   new(MONST"rattlesnake")->move(TO);
   		   break;
   		case 1:
    		  	new(MONST"koboldf1")->move(TO);
				new(MONST"koboldf")->move(TO);
				break;
    		case 2:	
    			new(MONST"koboldf2")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				break;
			}
		}
*/
}	