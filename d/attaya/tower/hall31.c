
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",1);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Dark room");
        set_long("
    This small room seems to have been designed as a guarded vault.  It has heavy metal plate walls, floor, and ceiling.  In the center of the far wall is a metal table.  
    You get the feeling that if something isn't in here, it should be.
");
       set_listen("default", "There is an uneasy calm in the stale air.");
       set_exits(([
       "north" : "/d/attaya/tower/hall30",
]));
       set_items(([
    "carpet" : "The dusty carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "rubble" : "Parts of the walls, mostly.  Lots of dust.",
    "ceiling" : "It is too dark to see.",
    "floor" : "A dusty blue and gold carpet covers the marble floor.",
    "table" : "The metal table has the outline of a long staff upon it, imprinted forever in the dust.",
    "plates" : "The heavy metal plates seem perfectly inpenetratable.",
    "walls" : "The walls are covered with sturdy metal plates.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
//  do_random_encounters(({"/d/attaya/obj/warpgate.c"}),50,1);
}
