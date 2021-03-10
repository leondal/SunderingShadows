
#include <std.h>
#include "lizard.h"
inherit WATER;


void create() {
   if(base_name(TO) != "/d/laerad/parnelli/asgard/sewer/deep1") {
    switch(random(18)) {
     case 0..2:	
	set_monsters( ({LMON+"lman", LMON+"plead"}), ({2, 1 })); 
	break;
     case 3:	
	set_monsters( ({LMON+"lman_youth", LMON+"warlead"}), ({2, 1 })); 
	break;
     case 4:	
	set_monsters( ({LMON+"lman"}), ({3}) ); 
	break;
     case 5:	
	set_monsters( ({LMON+"lman", LMON+"plead", LMON+"warlead"}), ({2, 1, 1}) ); 
	break;
     default:
	break;
    }
   }
   ::create();
   set_repop(40);
set_name("Underground Lake");
set("short","Dark and water filled cavern.");
  	set_terrain(DEEP_WATER);
  	set_travel(RUTTED_TRACK);
set("long","%^BOLD%^%^BLUE%^You are swimming in very cold water in a large cavern.  "+
        "The water is shallow in most places you have been, no more than waist "+
        "deep on a normal sized human.  Who can say if the it gets deeper the farther "+
        "you wade.  Stalactites dangle from the ceiling and glisten with a fine coat "+
        "of water.  The ceiling is high above you somewhere in the darkness.  %^RESET%^");
set_property("indoors",1);
	set_property("surface",1);
remove_property("underwater");
set_property("no teleport",1);
set_property("no invis",1);
set_property("no sticks",1);
set_property("light",1);
set_smell("default","The caves smell musty and damp.");
set_listen("default","An occasional drop from a stalactite splashes to the water.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, wet and cool to the touch.",
   "floor":"Littered with rubble from broken stalactites - watching your step and watching your head may prove interesting.",
   ({"stalactites","stalactite"}):"Hanging high above your head... sure hope they do not crash down upon you.",
   "water":"Very cold and dark, the water seeps inside your clothing like the kiss of death."
   ]));
}
