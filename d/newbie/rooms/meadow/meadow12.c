#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadoweast";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow16",
     //"east":MEADOW"meadow12",
     "south":MEADOW"meadow8",
     "west":MEADOW"meadow11",
   ]));
}
