#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_long(""+TO->query_long()+" There is a little hut to the north.");
   set("night long",""+TO->query("night long")+" There is a hut to the"+
   " north here.");
   set_exits(([
   "west" : ROOMS+"meadow17",
   "north" : ROOMS+"storage/hut4",
   "south" : ROAD+"road38",
   ]));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
       tell_object(TP,"You have to duck low to avoid hitting your head.");
   }
   return 1;
}
