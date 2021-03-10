#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Town of Solace");
    set_long(
@KAYLA
You seem to have entered the small town of Solace. Most of the buildings
along the main road are constructed of wood, with thatched roofs and
whitewashed or stuccoed walls. The Smithy, to the east, is of stone
and timber with a slate roof. The Hotel, to the west, is the only
building in the village with two complete stories.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/new/town2",
       "west" : "/d/deku/new/hotel",
       "east" : "/d/deku/new/smithy",
       "south" : "/d/deku/new/new5"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("gnome")) {
  new("/d/deku/monster/gnome1")->move(this_object());
  return 1;
  }
}
