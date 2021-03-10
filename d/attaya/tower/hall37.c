#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("That closet you were scared of as a kid");
    set_long("
    There's just something about a dark closet that is all at once horrifying and dangerous.  This is especially true in a dark closet inside a fortress filled with undead horrors, just off a gruesome bedroom.
    The walls are bare and cracked.  A few coat hangers lie at your feet and on a pole spanning the length of the closet.  A very dark hole is just above you, in the closets' ceiling.");

     set_smell("default","It is very calm in here.");
 
    set_exits(([
    "west" : "/d/attaya/tower/hall36",


    ] ));
   set_items(([
    "coathangers" : "The hangers are twisted metal wires with wooden slats running across the bottom from one side to the other to form a triangle.  The top of the wire forms a hook.",
    "walls" : "The plaster walls are bare and cracking.  They are sort of a light gray color.",
    "hole" : "There is a large square hole in the ceiling that you may be able to climb through.",
    "ceiling" : "It is white plaster with a large hole in it.",

    "rubble" : "Mostly bricks, and various wooden planks, nails, plaster and stone fragments, and metal shards.",
]));
}
void init() {
  ::init();
  add_action("climb", "climb");
}

int climb(string str) {
  if(str=="hole") {
  write("You pull yourself up using the closet bar, and climb through the hole in the ceiling.\n");
  say((string)this_player()->query_cap_name()+" jumps up to the closet bar, then climbs through the hole in the ceiling.\n");
  this_player()->move_player("/d/attaya/tower/hall38");
  return 1;
}
  return 0;
}
