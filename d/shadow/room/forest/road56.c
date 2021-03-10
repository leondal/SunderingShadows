//fork added to lead to road to Koenig.  Circe 11/29/03
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
   "The road travels to the northwest for some distance, it also"+
   " bends to the south here. The road seems to be in very good"+
   " shape here and you feel safe traveling along it. In the distance"+
   " to the southeast you can make out a city.  A narrow foot trail "+
   "branches off to the east."
   );
   set_smell("default","You smell the dust of the road.");
   set_listen("default","You hear the faint sounds of animals.");
   set_items(([
   "road" : "This is a well worn road that is in quite good shape.",
   ]));
   set_exits(([
   "northwest" : FORESTDIR+"road55",
   "south" : FORESTDIR+"road57",
   "east" : "/d/koenig/streams/trail8"
   ]));
}
