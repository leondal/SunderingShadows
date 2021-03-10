#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Gateway to the Abyss");
    set_long(
@KAYLA
Beyond the iron doors is a corridor with walls of red marble.  A thick 
black carpet runs from the entry to an ebony archway some 40 feet away.
The arched ceiling is of black marble shot through with bands of 
scarlet.  The walls and floor are polished and dust free.  From the
archway you can see a dim red glow that seems to come from the ceiling.
This eerie light pervades the entire passageway.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/dark/door",
       "north" : "/d/deku/dark/vault"
    ] ));
    set_items(([
    ] ));
}
