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
whitewashed or stuccoed walls. The Pub, to the north, is of stone
and timber with a slate roof. An ordinary alley is towards the south.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/new/pub",
       "west" : "/d/deku/new/town4",
       "east" : "/d/deku/new/town2",
       "south" : "/d/deku/new/alley"
    ] ));
set_listen("default","You hear some music coming from the pub to the north.");
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
