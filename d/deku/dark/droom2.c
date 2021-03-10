#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Passageway to the Abyss");
    set_long(
@KAYLA
%^YELLOW%^Passageway to the Abyss%^RESET%^
This passageway provides access to a network of caverns that connects
the Underdark to the surface world.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/dark/droom3",
       "south" : "/d/deku/dark/droom1"
    ] ));
    set_items(([
    ] ));
}
