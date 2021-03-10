#include <std.h>
#include "lizard.h"

inherit CROOM;

void create() {
   if(base_name(TO) != "/d/laerad/parnelli/asgard/sewer/watroom") {
    switch(random(25)) {
     case 0..2:	
	set_monsters( ({LMON+"lman", LMON+"plead"}), ({2, 1 })); 
	break;
     case 3:	
	set_monsters( ({LMON+"lman", LMON+"warlead"}), ({2, 1 })); 
	break;
     case 4:	
	set_monsters( ({LMON+"lman_youth"}), ({random(3)+1}) ); 
	break;
     case 5:	
	set_monsters( ({LMON+"lman", LMON+"plead", LMON+"warlead"}), ({2, 1, 1}) ); 
	break;
     default:
	break;
    }
   }
   ::create();
   set_repop(20);
  	set_terrain(SHALLOW_WATER);
  	set_travel(RUTTED_TRACK);
	set_name("Water cavern");
set_short("%^BLUE%^Dark and water filled cavern%^RESET%^");
set_long("%^BOLD%^%^BLUE%^You are standing in %^CYAN%^very cold water "
	"%^BLUE%^in a large cavern.  "+
        "The water is shallow in most places you have been, no more than waist "+
        "deep on a normal sized human.  Who can say if the it gets deeper the farther "+
        "you wade.  Stalactites dangle from the ceiling and glisten with a fine coat "+
        "of water.  The ceiling is high above you somewhere in the darkness.  %^RESET%^"
   );
   set_items(([
	"walls":"Much like what you would expect cave walls to be like, hard, wet and cool to the touch.",
	"floor":"Under the water, the floor is littered with rubble from broken stalactites large enough to trip over.  Watching your step and watching your head may prove interesting.",
   	({"stalactites", "stalactite" }):"Hanging high above your head...sure hope they do not crash down upon you.",
   	"water":"%^BLUE%^Very cold and dark, the water seeps inside your clothing like the kiss of death."
   ]));
   set_property("indoors",1);
   set_property("no teleport",1);
   set_property("no invis",1);
   set_property("no sticks",1);
   set_property("light",1);
}
