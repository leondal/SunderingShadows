#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(STAIRWAY);
    set_short("Grand stairs");
    set_long(
@KAYLA
%^YELLOW%^Grand Stairs%^RESET%^
The Grand Stair sweeps upward.  The stair, with its white marble
showing through even the thick cover of dust, is a relic of the
once proud masters of the Fortress.
KAYLA
    );
    set_listen("default","You hear disconcerting scuffling sounds in surrounding rooms.");
    set_exits(([
       "north" : "/d/deku/fortress/hallN5",
       "up" : "/d/deku/fortress/hallN6"
    ] ));
    set_items(([
    ] ));
}
