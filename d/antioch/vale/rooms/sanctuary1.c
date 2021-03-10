#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "south" : ROOMS+"entrance",
   "west" : ROOMS+"sanctuary2",
   "east" : ROOMS+"sanctuary9",
   "north" : ROOMS+"sanctuary6",
   ]));
}

void reset()
{
   ::reset();
   if(member_array("south",TO->query_exits()) == -1) {
      add_exit(ROOMS+"entrance", "south");
      //"/d/antioch/vale/rooms/entrance.c"->add_exit("north",ROOMS+"sanctuary1");
      tell_room(TO,"%^GREEN%^The brambles slowly move aside to allow"+
      " passage to the south once more.%^RESET%^");
      tell_room("/d/antioch/vale/rooms/entrance","%^GREEN%^The brambles"+
      " slowly move aside to allow passage to the north once more.%^RESET%^");
   }
}
