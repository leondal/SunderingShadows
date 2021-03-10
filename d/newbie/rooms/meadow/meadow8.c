#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadoweast";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow12",
     //"east":MEADOW"meadow8",
     "south":MEADOW"meadow4",
     "west":MEADOW"meadow7",
   ]));
}
