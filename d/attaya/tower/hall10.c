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
    You step into a grand hall.  Large doorways surround you.  The ceiling here forms a dome far above, painted with a mural.
    A magnificent staircase splits the room and splits to two staircases just above you.  The staircase enters the room diagonally, and across from its base to the northeast is a stained glass window.  Lightposts stand on either side of it and in the remaining 3 corners of the room.
    A large mirror hangs on the northern wall next to the doorway.  A fine sword hangs from the eastern wall.
");
       set_exits(([
       "north" : "/d/attaya/tower/hall17",
       "south" : "/d/attaya/tower/hall13",
       "west" : "/d/attaya/tower/hall11",
       "east" : "/d/attaya/tower/hall8",
        "staircase" : "/d/attaya/tower/staircase1",
]));
       set_items(([
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "walls" : "The walls are comprised of decorated tiles.",
     "staircase" : "The staircase enters the room at an angle and rises half way to the dome before splitting into two smaller staircases.  They vanish into rooms higher up.",
    "mural" : "The mural depicts the island of Attaya and the surrounding lands.",
    "sword" : "The sword shines in the light.",
    "window" : "The stained glass window opposite the staircase is a myriad of triangles, growing smaller in a spiral shape to the center.  The glass panels fade from blue on the outside to red in the center.",
    "lightposts" : "Brass posts hold tiers of five candles.  There are five in the room.",
    "dome" : "The great dome above you is painted with a mural.",
    "mirror" : "The mirror is enormous and reflects the entire room!",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/phalanx.c"}),45,1);
}
