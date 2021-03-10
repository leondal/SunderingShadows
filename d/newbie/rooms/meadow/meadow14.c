#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadownorth";

void create()
{
   ::create();
   set_exits(([
     //"north":MEADOW"meadow16",
     "east":MEADOW"meadow15",
     "south":MEADOW"meadow10",
     "west":MEADOW"meadow13",
   ]));
}
