#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Chamber of pool");
    set_long(
@KAYLA
A pool of %^YELLOW%^yellowish%^RESET%^ steaming water occupies this circular cavern.
Sickening and unwholesome vapors rise from the bubbling water.  
The atmosphere in the cave is reeking with a nauseating rotten
egg smell.
KAYLA
    );
     set_smell("default","The cave is reeking with an rotten egg smell.");
    set_exits(([
       "north" : "/d/deku/dark/door",
       "south" : "/d/deku/dark/elite3"
    ] ));
    set_items(([
"water" : "The yellowish pool may or may not be safe to drink.",
"pool": "The yellowish pool may or may not be safe to drink."
    ] ));
}
