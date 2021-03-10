#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadow";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow15",
     "east":MEADOW"meadow12",
     "south":MEADOW"meadow7",
     "west":MEADOW"meadow10",
   ]));
}
