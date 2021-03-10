//slide1.c

#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("A lavish hallway");
        set_long("
    This is a small connecting hall with greeinsh walls.  The lighting in here is somewhat dim, and it is very quiet.
    A large foyer lies just to the south, and another room to the west.  To the east is a great library!
");
       set_exits(([
       "west" : "/d/attaya/tower/hall16",
       "east" : "/d/attaya/tower/hall18",
       "south" : "/d/attaya/tower/hall10",
]));
       set_items(([
    "floor" : "A blue and gold carpet covers the marble floor.",
    "ceiling" : "The ceiling is made from large marble tiles just like the walls.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "walls" : "The walls are covered in a greenish parchment.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/warlock.c"}),55,1);
}
