
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",1);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Dark passageway");
        set_long("
    This is a once majectic hallway that now lies in a state of disrepair.  It has been sealed for who knows how long.  Rubble litters the floor.
");
       set_listen("default", "There is an uneasy calm in the stale air.");
       set_exits(([
       "north" : "/d/attaya/tower/hall27",
       "south" : "/d/attaya/tower/hall29",
]));
       set_items(([
    "carpet" : "The dusty carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "rubble" : "parts of the walls, mostly.  Lots of dust.",
    "walls" : "The old plaster walls are in need of refinishing.",
    "ceiling" : "It is too dark to see.",
    "floor" : "A dusty blue and gold carpet covers the marble floor.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/banisher.c"}),55,1);
}
