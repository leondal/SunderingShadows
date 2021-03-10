#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Dining Hall");
    set_long(
@KAYLA
%^YELLOW%^Dining Room%^RESET%^
For some reason, this elegant room escaped the destruction that
is throughout the rest of the fortress.  A shiny table made of
smooth vallenwood occupies the center of the room.  It is 
surrounded by a dozen finely crafted chairs.  An undamaged carpet
covers the floor.  Three golden chandeliers hang from the ceiling
each ablaze with dozens of candles.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/fortress/hallE1",
       "east" : "/d/deku/fortress/kitchen2"
    ] ));
    set_items(([
	"table" : "The table is set for four, with fine china and silver."
    ] ));
}
