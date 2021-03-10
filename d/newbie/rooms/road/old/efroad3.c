//efroad3.c

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
You are on a narrow dirt trail between the forest to the southwest
and the road to the northeast. You are not quite on the edge of the
forest here, the trees and plants are gathered close around you.
JAVAMAKER
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind in the trees.");
   set_exits(([
      "south":ROAD"efroad4",
      "northeast":ROAD"efroad2",
   ]));
   set_items(([
       "trail":"The dirt is hard-packed beneath your feet.",
       ({"trees","plants"}):"The trees and plants are plentiful here, very lush and green.",
   ]));
}
