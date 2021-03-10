
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("A balcony high within a library");
        set_long("
    You are standing on a large balcony that runs all the way around this room.  You are about 3 stories above the ground and, below, you see the main floor of the library covered with bookcases.
    A ladder runs up to a level above this one and to a level below this one.
");
       set_exits(([
       "west" : "/d/attaya/tower/hallb2",
       "south" : "/d/attaya/tower/hallb4",
       "up" : "/d/attaya/tower/hall22",
       "down" : "/d/attaya/tower/hall23",
]));
       set_items(([
    "ceiling" : "The ceiling is carpeted just as the floor is.  It is almost like looking into a mirror!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "walls" : "The walls are comprised of decorated tiles.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
    void init() {  
   ::init();
  do_random_encounters(({"/d/attaya/mon/supersolstice.c"}),5,1);
}
