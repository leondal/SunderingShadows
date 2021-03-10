
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",0);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Darkened vent");
        set_long("
    This dark passage creaks and moans from unseen pressures that still act upon it hundreds of years after the construction of these halls.  A faint light comes from the west, otherwise, all is dark.
");
       set_listen("default", "The walls creak.");
       set_exits(([
       "west" : "/d/attaya/tower/hall40",
       "east" : "/d/attaya/tower/hall38",
]));
       set_items(([
      "light" : "It comes from the west...",
    "ceiling" : "It is too dark to see.",
    "floor" : "A dusty blue and gold carpet covers the marble floor.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
