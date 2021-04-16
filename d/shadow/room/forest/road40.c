#include <std.h>
#include "forest.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(MEADOWLANDS);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_short("Path through the Meadow Lands");
   set_long(
   "%^BOLD%^You are walking on a path on the edge of the meadow lands.%^RESET%^\n"+
   "The road stretches out to the north and south here, north leads"+
   " into the meadow lands and south leads further away from it back into"+
   " a light forest and brush lands.\n"
   );
   set_smell("default","You smell the fresh air.");
   set_listen("default","You can hear animals in the brush.");
   set_items(([
   "road" : "This is really just a glorified dirt path, but someone keeps"+
   " it in good shape.",
   "brush" : "Brush grows along the edges of the road here, slowly getting"+
   " higher. You can hear animals rustling around.",
   ]));
   set_exits(([
   "north" : FORESTDIR+"road39",
   "south" : FORESTDIR+"road41",
   ]));
}
