#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadow";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow10",
     "east":MEADOW"meadow7",
     "south":MEADOW"meadow2",
     "west":MEADOW"meadow5",
   ]));
}
