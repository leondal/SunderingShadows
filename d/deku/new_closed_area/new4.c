#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",0);
   set_short("Kobold Forest");
    set_long(
@KAYLA
You are within the realm of Kobold Caverns.  The forest seems to endlessly
extend to the west, and to the north is the side of a wooden structure.
The light also seems to become dimmer as you journey westward.
KAYLA
    );
    set_listen("default","You hear birds singing within the trees.");
    set_exits(([
       "west" : "/d/deku/new/new5",
       "east" : "/d/deku/new/new3"
    ] ));
    set_items(([
    ] ));
}
