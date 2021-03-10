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
   "The road stretches out to the northwest, leading into some grassy"+
   " plains, as well as further to the east, bending to the southeast"+
   " some ways ahead. The road seems to be in much better shape here,"+
   " and you feel much safer traveling along it now."
   );
   set_smell("default","You smell the dust of the road.");
   set_listen("default","You hear the faint sounds of animals.");
   set_items(([
   "road" : "This is a well worn road that is in quite good shape.",
   ]));
   set_exits(([
   "northwest" : FORESTDIR+"road49",
   "east" : FORESTDIR+"road51",
   ]));
}
