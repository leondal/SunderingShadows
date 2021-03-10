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
You are among the trees of the Kobold forest.  The creatures who 
dwell within the forest must not be accustomed to strangers.  Fog
begins to blanket the forest, and through the fog towards the west
lies an ongoing path, and to the east is the entrance to the 
small village.
KAYLA
    );
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/new7",
       "east" : "/d/deku/new/new5"
    ] ));
    set_items(([
       "trees" : "The large trees seem to waver in the blowing breeze."
    ] ));
}
