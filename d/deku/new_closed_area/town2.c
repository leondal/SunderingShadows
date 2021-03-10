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
whitewashed or stuccoed walls. The Tavern, to the north, is of stone
and timber with a slate roof. The General store is towards the east,
its a small wooden structure with a thatched roof.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/new/inn",
       "east" : "/d/deku/new/general",
       "west" : "/d/deku/new/town3",
       "south" : "/d/deku/new/town1"
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
