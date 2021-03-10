
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",1);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Dark passageway");
        set_long("
    The darkness almost seems to move around you.  Shadows as if alive grasp at you yet you push onward.  You feel a little of the darkness in your soul now.  This place has forever changed you.  The world will forever be a little darker.
");
       set_listen("default", "There is an uneasy calm in the stale air.");
       set_exits(([
       "west" : "/d/attaya/tower/hall34",
       "east" : "/d/attaya/tower/hall32",
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
  do_random_encounters(({"/d/attaya/mon/poltergeist.c"}),45,1);
}
