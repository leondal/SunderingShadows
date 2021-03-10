#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadownortheast";

void create()
{
   ::create();
   set_exits(([
     //"north":MEADOW"meadow16",
     //"east":MEADOW"meadow16",
     "south":MEADOW"meadow12",
     "west":MEADOW"meadow15",
   ]));
}
