
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
    All around you, younger trees rush to take the place of fallen ones.  Tropical foliage with enormous leaves make you feel as though you are walking through a chest-high pool of lilypads.
    An algae covered lake lies to the north.  Several dead trees rise from its waters and you can see a small temple on the other side..
");
       set_exits(([
         "south":"/d/attaya/jun95",
         "west":"/d/attaya/jun98",
         "east":"/d/attaya/jun100",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "The palm trees rustle above you.");
set_items(([
    "canopy": "It completely blocks out the light.",
    "temple" : "It is covered by vines and made of weathered marble.  It is just across the lake.",
    "lake" : "It extends into the jungle to the east and the surface of the water is covered in a thick layer of bright green algae.",
    "trees" : "Dead stumps rise like ghosts from the water of the lake.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
}

void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/archer","/d/attaya/mon/archer2","/d/attaya/mon/phalanx","/d/islands/common/mon/scorpion","/d/attaya/mon/nightstalker","/d/attaya/mon/poltergeist", "/d/attaya/mon/uwarrior","/d/attaya/mon/toclahar","/d/islands/common/mon/necrophidius"}),30,6);
}
