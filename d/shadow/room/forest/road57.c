#include <std.h>
#include "forest.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_short("On a Quiet Road");
   set_long(
   "%^BOLD%^You are walking along a quiet road.%^RESET%^\n"+
   "The road bends to the north here, it also continues to the"+
   " southeast. The road seems to be in very good shape here"+
   " and you feel safe traveling along it. A ways ahead to the southeast"+
   " you can make out a city."
   );
   set_smell("default","You smell the dust of the road.");
   set_listen("default","You hear the faint sounds of animals.");
   set_items(([
   "road" : "This is a well worn road that is in quite good shape.",
   ]));
   set_exits(([
   "north" : FORESTDIR+"road56",
   "southeast" : FORESTDIR+"road58",
   ]));
}
