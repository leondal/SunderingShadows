#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadow";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow14",
     "east":MEADOW"meadow11",
     "south":MEADOW"meadow6",
     "west":MEADOW"meadow9",
   ]));
}
