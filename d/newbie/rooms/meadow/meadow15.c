#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadownorth";

void create()
{
   ::create();
   set_exits(([
     //"north":MEADOW"meadow16",
     "east":MEADOW"meadow16",
     "south":MEADOW"meadow11",
     "west":MEADOW"meadow14",
   ]));
}
