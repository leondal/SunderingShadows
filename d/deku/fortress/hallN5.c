#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Shadowlord fortress");
    set_long(
@KAYLA
%^YELLOW%^Northern Hallway%^RESET%^
This hallway is furnished with great care, creating an atmosphere 
of comfort and luxury.  A plush purple carpet covers the floor,
and many tapestries of bright red and golden colors decorate the
walls.  There are doors to either side of the hallway.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/fortress/stair2",
       "north" : "/d/deku/fortress/hallN4",
       "west" : "/d/deku/fortress/lair",
       "east" : "/d/deku/fortress/heads"
    ] ));
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_items(([
    ] ));
}
