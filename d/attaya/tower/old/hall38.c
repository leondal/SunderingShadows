
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",0);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Darkened vent");
        set_long("
    You get the feeling that you are not safe here.  The only light comes from tiny cracks far to the west.  A hole in the floor opens into the closet beneath you.
");
       set_listen("default", "The walls creak.");
       set_exits(([
       "down" : "/d/attaya/tower/hall37",
       "west" : "/d/attaya/tower/hall39",
]));
       set_items(([
    "carpet" : "The dusty carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
      "hole" : "A square hole in the floor opens out into the closet that you were just in.",
      "light" : "It comes from the west...",
    "rubble" : "Parts of the walls, mostly.  Lots of dust.",
    "doorway" : "It is completely sealed.",
    "walls" : "The old plaster walls are in need of refinishing.",
    "ceiling" : "It is too dark to see.",
    "floor" : "A dusty blue and gold carpet covers the marble floor.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
