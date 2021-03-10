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
You are on a very thin trail, through a lightly wooded forest.  The forest
seems to endlessly extend to the west, and to the east is the entrance
gate. This seems to be a very comfortable environment.  The light also
seems to become dimmer far to the west.
KAYLA
    );
   set_listen("default","You hear birds singing within the trees.");
    set_exits(([
       "west" : "/d/deku/new/new002",
       "east" : "/d/deku/new/new2"
    ] ));
    set_items(([
    ] ));
}
