#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_long(""+TO->query_long()+" There is a little hut to the south.");
   set("night long",""+TO->query("night long")+" There is a hut to the"+
   " south here.");
   set_exits(([
   "east" : ROOMS+"meadow7",
   "north" : ROOMS+"meadow5",
   "south" : ROOMS+"storage/hut3",
   ]));
   set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
       tell_object(TP,"You have to duck low to avoid hitting your head.");
   }
   return 1;
}
