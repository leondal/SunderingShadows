//wfroad2.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_short("A dirt trail");
   set_long(
@JAVAMAKER
You are on a narrow dirt trail between the forest to the northeast
and the road to the southwest. You are near the edge of the forest here,
and the trees and plants are scattered.
JAVAMAKER
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind in the trees.");
   set_exits(([
      "northeast":ROAD"wfroad3",
      "southwest":ROAD"wfroad1",
   ]));
   set_items(([
       "trail":"The dirt is hard-packed beneath your feet.",
       ({"trees","plants"}):"The trees and plants are sparse here, but very lush and green.",
   ]));
}
