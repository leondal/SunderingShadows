
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Mysterious hallway within the Kinnesaruda fortress");
        set_long("
    This is a small brick passageway just wide enough for one person to walk through.  The walls are smooth and made from dark gray marble tiles as is the floor.
    The passage here is so narrow that you are forced to sidestep.  An opening in the wall in front of you would provide some relief.
");
       set_exits(([
       "north" : "/d/attaya/tower/hallb5",
       "west" : "/d/attaya/tower/hallb9",
      "east" : "/d/attaya/tower/hallb8",
]));
       set_items(([
    "floor" : "It is made of dark gray marble tiles.",
    "walls" : "They are made of dark gray marble tiles.",
    "ceiling" : "It is made of white planks.",
]));
	
}
