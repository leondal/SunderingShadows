
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Boring room within the Kinnesaruda fortress");
        set_long("
    At the end of the foyer is this dim room.  The walls, ceiling, and floor are made of cold stone, and you notice a rusty metal grate swung inward behind you.  Several shackles suspend skeletal arms and ribcages above the ground, and other bones lie in piles beneath them.
    At your feet, a skull peers sadly up at you, lacking the familiar skeletal grin.
");
       set_listen("default", "%^BOLD%^%^RED%^You hear water dripping.");
       set_exits(([
       "east" : "/d/attaya/tower/hall11",
]));
       set_items(([
    "floor" : "It is made of white tiles..",
    "walls" : "They are made of white tiles.",
    "ceiling" : "It is made of white tiles.",
    "tube" : "The tube is spinning and swaying from a thin cable attached to the ceiling.",
    "cable" : "Nothing unusual.",
    "colors" : "The colors flash against the walls...  They are making you feel %^BOLD%^R%^RED%^E%^BLUE%^A%^GREEN%^L%^YELLOW%^L%^RESET%^%^MAGENTA%^Y %^CYAN%^D%^BOLD%^%^BLACK%^I%^RESET%^%^RED%^Z%^ORANGE%^Z%^BOLD%^%^MAGENTA%^Y%^RESET%^!",
]));
	
}
void reset(){
        ::reset();
    if(!present("bench"))
      new("/d/attaya/tower/obj/bench")->move(this_object());
}
