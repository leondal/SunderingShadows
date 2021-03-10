
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Grand Staircase");
        set_long("
    You are climbing a staircase in the main hall.  It splits here and rises as two separate staircases, one to the right, and one to the left.  A suit of armor stands here at the convergence of the two staircases.
");
       set_exits(([
       "left" : "/d/attaya/tower/hallc11",
       "right" : "/d/attaya/tower/hallc13",
]));
       set_items(([
    "ceiling" : "The ceiling is carpeted just as the floor is.  It is almost like looking into a mirror!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "walls" : "The walls are comprised of decorated tiles.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "armor" : "It stands on a pedestal and shines brilliantly.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
