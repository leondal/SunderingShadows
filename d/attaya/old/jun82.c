
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(JUNGLE);
      set_travel(FRESH_BLAZE);
	set_short("Old growth jungle.");
	set_property("indoors",0);
	set_property("light",2);
set_long("
    This part of the jungle is very old...  Tall royal palms stretch high into the sky letting a little more light through the higher canopy.
    Large stone blocks are embedded in the mud here.  They are marked with various carvings.  
");
       set_exits(([
         "north":"/d/attaya/jun87",
         "west":"/d/attaya/jun81",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "The palm trees rustle above you.");
set_items(([
    "canopy": "It completely blocks out the light.",
    "blocks" : "They are enormous blocks of sandstone.  Symbols are still visible in their weathered sides.",
    "carvings" : "The symbols are unfamiliar to you.",
    "symbols" : "They are in an ancient script...  Most likely a warning to trespassers.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
}

void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/nightstalker.c","/d/attaya/mon/poltergeist.c", "/d/attaya/mon/phalanx.c","/d/attaya/mon/toclahar.c","/d/attaya/mon/necrophidius.c"}),30,6);
}
