
#include <std.h>

inherit CROOM;

void create(){
    set_monsters(({"/d/attaya/mon/solstice"}),({random(5)+1}));
	::create();
      set_terrain(JUNGLE);
      set_travel(DIRT_ROAD);
	set_name("Trail carved through the jungle on Attaya Island.");
	set_short("Trail carved through the jungle on Attaya Island.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    You are pushing your way down a trail carved through the thicket of the jungle.  Tall tropical trees and palms form a canopy above you so thick that it blocks out nearly all the sunlight!  The ground beneath your feet sloshes with each step.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
");
       set_exits(([
          "west":"/d/attaya/jun53",
         "east":"/d/attaya/jun55"
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna");
	}

