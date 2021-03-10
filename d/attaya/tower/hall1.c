
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
    ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Inside the heart of the Kinnesaruda");
        set_long("
    The hallway ends here.  A large room is just to the west of you.  The final two sculptures here are unlike the others and catch your eye.  The walls by the entrance to the room are plated with metal.
    The ceiling above you is carpeted like the floor.
");
       set_exits(([
       "west" : "/d/attaya/tower/hall4",
       "east" : "/d/attaya/tower/hall2a",
]));
       set_items(([
    "ceiling" : "The ceiling is carpeted just as the floor is.  It is almost like looking into a mirror!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "sculptures" : "The final two sculptures at the end of the long lines running the full length of the hallway are shorter than the others.  The hands of the figures are outstretched and grasp glass spheres.",
    "spheres" : "The spheres contain a strange greenish gas.",
    "walls" : "The walls are comprised of decorated tiles.  By the entrance to the room to the west, large metal plates cover the walls on either side.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "plates" : "The heavy iron plates seem to have been added recently",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
