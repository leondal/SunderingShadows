#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow8",
   "east" : ROAD+"road32",
   "north" : ROOMS+"meadow2",
   "south" : ROAD+"road33",
//   "temple" : "/d/magic/temples/lath_courtyard", //changed by Circe because of temple upgrades 12/5/03
   ]));
}
