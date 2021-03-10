
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("A balcony high within a library");
        set_long("
    You are standing on a large balcony that runs all the way around this room.  You are about 2 stories above the ground, and below, you see the main floor of the library covered with bookcases.
    A large wall of granite bricks lies to the west.  It has been reinforced with alloy beams that run like a spiderweb over the walls' surface.  A doorway has been sealed by a wall of bricks here.  The work appears very sloppy as if it were done with great haste.
    A few of the bricks near the floor have fallen out making a small opening.
");
       set_exits(([
       "north" : "/d/attaya/tower/hall24",
       "east" : "/d/attaya/tower/hall26",
]));
       set_items(([
    "ceiling" : "The ceiling is carpeted just as the floor is.  It is almost like looking into a mirror!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "walls" : "The walls are comprised of decorated tiles except for the highly reinforced stone wall to the west..",
    "wall" : "The western wall is highly reinforced with metal beams and is itself made of enormous stone blocks that must way upwards of a ton each!  The wall has been designed to keep something contained within, perhaps.",
    "west wall" : "The western wall is highly reinforced with metal beams and is itself made of enormous stone blocks that must way upwards of a ton each!  The wall has been designed to keep something contained within, perhaps.",
    "brick wall" : "A wall of bricks has been built to block off a doorway leading west.  It has been put up with great haste.",
    "opening" : "A few of the bricks in the wall have fallen out leaving an opening big enough to squeeze through if you are careful.  Darkness lies just beyond.",
    "bricks" : "They form a wall in a doorway.",
    "doorway" : "There is the obvious shape of a door here, even the wooden frame remains, but within it is a wall of bricks designed to seal off whatever lies beyond.",
    "western wall" : "The western wall is highly reinforced with metal beams and is itself made of enormous stone blocks that must way upwards of a ton each!  The wall has been designed to keep something contained within, perhaps.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
  add_action("squeeze", "squeeze");
}
int squeeze(string str) {
  if(str=="through opening") {
  write("You carefully squeeze through the small opening in the bricks.\n");
  say((string)this_player()->query_cap_name()+" squeezes through the small opening in the bricks.\n");
  this_player()->move_player("/d/attaya/tower/hall27");
  return 1;
}
  return 0;
}
