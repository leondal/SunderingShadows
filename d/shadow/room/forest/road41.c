#include <std.h>
#include "forest.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_short("Path through the Brush");
   set_long(
   "%^BOLD%^You are walking on a path through the brush.%^RESET%^\n"+
   "The road stretches out to the north and south here. To the north"+
   " you can see the meadow lands. The brush grows higher further south.\n"
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
   "north" : FORESTDIR+"road40",
   "south" : FORESTDIR+"road42",
   ]));
}
