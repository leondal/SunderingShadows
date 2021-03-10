#include <std.h>

inherit ROOM;

object air;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Gateway to the Abyss");
    set_long(
@KAYLA
The air is uncomfortably thin and dry in this large chamber.  There
is no breeze, and no insects are present in this section of the
caverns.  Still there is something here, something you don't notice
until the air thins.
KAYLA
    );
      set_exits((["west" : "/d/deku/dark/room6"]));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("air")) {
    new("d/deku/monster/air")->move(this_object());
  }
}

