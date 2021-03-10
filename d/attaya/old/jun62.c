
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(RUINS);
      set_travel(FOOT_PATH);
	set_name("Lost graveyard.");
	set_short("Lost graveyard.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    You are walking between the crumbling stone markers of a forgotten graveyard.  It has been overgrown, and in most places is unrecognizible as such.  The darkness caused by the canopy of leaves above you gives this place a feeling of despair and loneliness.  
    A few scattered bones lie half buried in the nearby mud.  An old stone wall winds it's way through the graveyard.
");
       set_exits(([
          "west":"/d/attaya/jun61",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "It is strangely quiet.  The animals have all been %^RED%^silenced!");
set_items(([
    "markers": "They are too old to read, but many bear the insignea of the Kinnesaruda or 'Black Dawn'.",
    "canopy": "It completely blocks out the light.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "wall": "It has been reduced to mere rubble in places.  It is hardly discernible",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
}

void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/bwyvern.c","/d/attaya/mon/guardian.c", "/d/attaya/mon/uwarrior.c","/d/attaya/mon/spiritdancer.c","/d/attaya/mon/necrophidius.c"}),50,3);
}
