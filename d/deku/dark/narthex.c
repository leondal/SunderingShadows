#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Narthex to the Mausoleum");
    set_long(
@KAYLA
Narthex to the Mausoleum
A %^RED%^red%^RESET%^ firelight greets you as you open the doors to the entryway
of the mausoleum.  The room is panelled in polished black stone
flecked with small silver specks.  Four pillars of the same material
rise near the corners of the room, and stone pegs jut from all sides
of the wall.  There is a stairway leading down into darkness.
KAYLA
    );
    set_exits(([
       "out" : "/d/deku/open/mausoleum",
       "down" : "/d/deku/dark/stair1"
    ] ));
    set_items(([
    ] ));
}
