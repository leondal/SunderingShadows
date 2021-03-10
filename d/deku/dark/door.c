#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Great Iron Doors");
    set_long(
@KAYLA
You see a pair of riveted iron doors.  Each door is 9 feet wide and
21 feet tall.  From the look of the hinges set into the stone, each of
these great doors must be at least 1 foot thick.  On each valve are
many leering demon visages in bronze.  Weird symbols form a crabbed
tracery around the border of each great iron portal.  In the center
of each is a plaque with some %^RED%^runes%^RESET%^.
KAYLA
    );
    set_exits(([ "north" : "/d/deku/dark/hall7",
                 "south" : "/d/deku/dark/pool"
    ]));
    set_items(([
      "runes": " %^GREEN%^ \n"+
               "    Deadlord treasure rests within.\n"+
               "    His curse on any who disturb it.\n"+
              "    Seek no further to steal it, nor\n"+
              "    To free he who is prisoned here.\n"+
              "    For a fate worse than death is\n"+
              "    Sure to come to those fools who\n"+
              "    Violate this circumscribed place.\n"
     ] ));
}
