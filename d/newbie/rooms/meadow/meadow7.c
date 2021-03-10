#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadow";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow11",
     "east":MEADOW"meadow8",
     "south":MEADOW"meadow3",
     "west":MEADOW"meadow6",
   ]));
}
