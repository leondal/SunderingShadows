
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",1);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Sealed hall");
        set_long("
    This hallway has been sealed by brick.  It is impossible to pass beyond this point.
");
       set_listen("default", "The bricks seem to crack as they settle.");
       set_exits(([
       "north" : "/d/attaya/tower/hallc11",
]));
       set_items(([
    "carpet" : "The dusty carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "rubble" : "parts of the walls, mostly.  Lots of dust.",
    "doorway" : "It is completely sealed.",
    "walls" : "The old plaster walls are in need of refinishing.",
    "ceiling" : "It is too dark to see.",
    "floor" : "A dusty blue and gold carpet covers the marble floor.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
    "bricks" : "They have been added recently and are bright red clay bricks bound by white mortar.",
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/poltergeist.c"}),55,1);
}
