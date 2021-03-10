#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "east" : PATH+"road19",
   "west" : PATH+"road21",
   "south" : "/d/player_houses/valas/rooms/entrance",
   ]));
}
