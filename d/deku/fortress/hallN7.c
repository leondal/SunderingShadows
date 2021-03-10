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
of luxury.  A thick black carpet covers the floor and the walls
are made of red marble.  From the archways, to the east and west,
there is a dim red glow that seems to come from the ceilings. This
eerie light pervades the entire hallway.  The archway toward the
north leads into pure darkness.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/fortress/hallN6",
       "north" : "/d/deku/fortress/throne",
       "west" : "/d/deku/fortress/vault2",
       "east" : "/d/deku/fortress/vault"
    ] ));
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_items(([
    ] ));
}
