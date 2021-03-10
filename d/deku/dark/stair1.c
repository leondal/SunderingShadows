#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(STAIRWAY);
    set_short("Stairway to the Abyss");
    set_long(
@KAYLA
As you enter the halls of the damned, drifting flurries of pain
penetrate your seemingly pathetic soul.  Shades of death cast
nightmarish images of death upon the scaly walls.  Spirits
damned to rot in blood-laced misery plague the burning air.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/dark/hall1",
       "west" : "/d/deku/dark/hall4",
       "south" : "/d/deku/dark/elf6",
       "up" : "/d/deku/dark/narthex"
    ] ));
    set_items(([
    ] ));
}
