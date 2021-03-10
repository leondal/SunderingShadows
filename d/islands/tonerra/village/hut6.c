#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("Empty Hut");
  set_long(
@DESC
This is a small hut that apparently is where someone lives.
There is a wooden table and chairs in the middle of the floor,
and a few other scattered pieces of furniture around the room.
It is empty now, but the owner could come back at any time.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell cooking food.");
  set_exits(([
    "north":I_VILLAGE+"vil79",
  ]));
}
