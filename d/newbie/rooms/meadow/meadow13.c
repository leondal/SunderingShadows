#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadownorthwest";

void create()
{
   ::create();
   set_exits(([
     //"north":MEADOW"meadow16",
     "east":MEADOW"meadow14",
     "south":MEADOW"meadow9",
     //"west":MEADOW"meadow11",
   ]));
}
