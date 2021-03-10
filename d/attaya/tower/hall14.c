
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Boring room within the Kinnesaruda fortress");
        set_long("
    This is a small square room with white walls, ceiling, and floor.  Above you, a spinning metal tube shoots kaleidoscopic colors in all directions against the walls.  
    You begin to feel dizzy.
");
       set_listen("default", "%^BOLD%^%^RED%^The dizzying array of colors is giving you a headache.");
       set_exits(([
       "east" : "/d/attaya/tower/hall7",
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
     new("d/attaya/obj/bench")->move(this_object());
}
