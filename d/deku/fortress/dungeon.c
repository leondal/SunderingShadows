#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Shadowlord Dungeon");
    set_long(
@KAYLA
%^YELLOW%^Dungeon Chamber%^RESET%^
Beyond a narrow archway is a damp and filthy chamber filled with
tools from a darker era.  From the entrance you can see a ramshackle
torture rack in the center of the room and a spiked iron cage hanging
from the ceiling by rusted chains.  Other devices from stone daggers
to thumbscrews, vises to hammers, are strewn about as well.  Half
buried in the dirt are the skeletons of two individuals who met
their end here years ago.
KAYLA
    );
    set_smell("default","A strongly revolting death smell.");
    set_exits(([
       "up" : "/d/deku/fortress/hallW4",
       "north" : "/d/deku/fortress/torture"
    ] ));
    set_items(([
    ] ));
}
