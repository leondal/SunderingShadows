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
    This is a small foyer.  A couple small tables hold candles.  The walls, and ceiling are marble and you are surrounded by columns.
    There are rooms to the south, and to the west.
");
   set_listen("default", "You hear the caw of a crow from room to the south!");
       set_exits(([
       "west" : "/d/attaya/tower/hall15",
       "east" : "/d/attaya/tower/hall10",
       "south" : "/d/attaya/tower/hall12",
]));
       set_items(([
    "floor" : "A blue and gold carpet covers the marble floor.",
    "ceiling" : "The ceiling is made from large marble tiles just like the walls.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "columns" : "There are about 6 marble columns that support the tiles on the ceiling.",
    "crow" : "crow?  What crow?",
    "tables" : "Two small tables sit against the walls.",
    "candles" : "A few candles sit on the tables.  They are substantially burned down.",
    "walls" : "The walls are comprised of marble tiles.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/warlock.c"}),55,1);
}
