#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Torture Chamber");
    set_long(
@KAYLA
%^YELLOW%^Torture Chamber%^RESET%^
Macabre and diabolical, this large room bears the unmistakable signs
of a torture chamber.  Manacles hang from the walls all around the 
west section.  In the northeast corner, a large iron box sits atop
a table.  In the southwest portion of the chamber is a torture rack
and wheel.
KAYLA
    );
     set_smell("default","A strongly revolting death smell.");
    set_exits(([
       "north" : "/d/deku/fortress/cell1",
       "south" : "/d/deku/fortress/dungeon"
    ] ));
    set_items(([
       "rack" : "Its an ancient machine use for torturing people.",
       "box" : "Its a strangely odd looking box with no opening or locks."
    ] ));
}
