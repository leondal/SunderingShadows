#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadowwest";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow13",
     "east":MEADOW"meadow10",
     "south":MEADOW"meadow5",
     //"west":MEADOW"meadow7",
   ]));
}
