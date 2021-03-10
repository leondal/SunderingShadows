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
   set_short("Bridge on a Quiet Road");
   set_long(
     "%^BOLD%^Bridge on a Quiet Road%^RESET%^\n"+
     "The road travels to the northwest and southeast for some "
     "distance.  A sturdy stone and wood bridge spans the Sarcosta "
     "River here.  The bridge seems to be in very good shape "
     "and occasionally you can see a ferry pass by below as it "
     "carries passengers along the river.  To the southeast you "
     "can make out a city."
   );
   set_smell("default","You smell the dust of the road.");
   set_listen("default","You hear the faint sounds of animals.");
   set_items(([
   "road" : "This is a well worn road that is in quite good shape.",
   ]));
   set_exits(([
   "northwest" : FORESTDIR+"road54",
   "southeast" : FORESTDIR+"road56",
   ]));
}
