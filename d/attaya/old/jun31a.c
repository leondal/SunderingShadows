
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
     %^BOLD%^%^RED%^You are almost hit by a burning palm tree as it falls across the path!
%^RESET%^    The volcanic valley yields to the lush jungle here.  A few trees are burning around you.  The jungle is dark and forbidding, but it is a welcome change from the unsure landscape around you.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
%^YELLOW%^Torches line the paths and give you some safety as many creatures of the dark jungle dislike the light.
");
       set_exits(([
          "north":"/d/attaya/jun32",
          "south":"/d/attaya/jun30",
]));
	
      set_smell("default", "The air smells of smoke and is difficult to breathe");
      set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna and the crackling of burning flora");
	
}
