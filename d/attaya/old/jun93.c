
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(JUNGLE);
      set_travel(FRESH_BLAZE);
	set_short("Old growth jungle.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    This part of the jungle is very old...  Tall royal palms stretch high into the sky letting a little more light through the higher canopy.
    All around you, younger trees rush to take the place of fallen ones.  Tropical foliage with enormous leaves make you feel as though you are walking through a chest-high pool of lilypads.
");
       set_exits(([
         "west":"/d/attaya/jun92",
          "east":"/d/attaya/jun94",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "It is strangely quiet.  The animals have all been %^RED%^silenced!");
set_items(([
    "canopy": "It completely blocks out the light.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
}

void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/nightstalker","/d/attaya/mon/entity", "/d/attaya/mon/uwarrior","/d/attaya/mon/toclahar","/d/islands/common/mon/necrophidius"}),50,6);
}
