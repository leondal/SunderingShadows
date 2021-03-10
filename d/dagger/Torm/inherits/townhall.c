#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light",2);
  set_smell("default","A slightly musty odor hangs in the air.");
  set_listen("default","You hear the footsteps of guards patrolling the halls.");
  set_items(([
    "nothing":"It's nothing at all.",
  ]));
}
