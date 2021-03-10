
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(JUNGLE);
      set_travel(DIRT_ROAD);
	set_name("Path carved through the jungle on Attaya Island.");
	set_short("Path carved through the jungle on Attaya Island.");
	set_property("indoors",0);
	set_property("light",2);
set_long("
    Tall tropical trees and palms form a canopy above you so thick that it blocks out nearly all sunlight!  At ground level, thorned brush and vines limit motion off the set path and those carved by large animals.  The humidity is hangs like a wet cloth on your face.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
%^YELLOW%^Torches line the paths and give you some safety as many creatures of the dark jungle dislike the light.
");
       set_exits(([
          "southwest":"/d/attaya/jun1",
          "east":"/d/attaya/jun3",
         "south":"/d/attaya/jun36"
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna");
	
}
