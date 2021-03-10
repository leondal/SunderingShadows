
#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_short("Volcanic rift valley.");
	set_property("indoors",0);
	set_property("light",2);
set_long("
    You stand within a volcanic rift valley.  Great heat rises from the ground all around you.  A tall cliff rises to the north, and to the west, burning palm trees create a wall of flame.  The valley opens up to the east.
");
       set_exits(([
          "south":"/d/attaya/jun31a",
         "east":"/d/attaya/jun33"
]));
	
      set_smell("default", "%^BOLD%^%^BLACK%^The thick smoke assaults your nose and stings your eyes");
      set_listen("default", "The ground around you rumbles.");
	
}
