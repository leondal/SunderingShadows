
#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_name("Path carved through the jungle on Attaya Island.");
	set_short("Path carved through the jungle on Attaya Island.");
	set_property("indoors",0);
	set_property("light",2);
set_long("
    The jungle ends here suddenly and you are assaulted by incredible heat!  Before you stretches a volcanic rift valley.  Burning palm trees surround you and the ground is quite unstable so it would be wise to move.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
%^YELLOW%^Torches line the paths and give you some safety as many creatures of the dark jungle dislike the light.
");
       set_exits(([
          "north":"/d/attaya/jun32",
          "south":"/d/attaya/jun30",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna");
	
}
