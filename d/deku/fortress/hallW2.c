#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Shadowlord Fortress");
    set_long(
@KAYLA
%^YELLOW%^Western Hallway%^RESET%^
This large hallway echoes softly with the sounds of any passage, 
quiet though it is.  Puffs of dust rise with each footfall on the
floor.  Here again is an area that seems not to have known the 
passage of a single, living soul.  Cobwebs festoons the hallway
and the woodwork looks rather rotten.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/fortress/rec_room",
       "west" : "/d/deku/fortress/hallW3",
       "east" : "/d/deku/fortress/hallW1"
    ] ));
    set_listen("default","You hear disconcerting scuffling sounds in surrounding rooms.");
    set_items(([
       "columns" : "These are plain supports with no ornate carvings or unusual shapes."
    ] ));
}
