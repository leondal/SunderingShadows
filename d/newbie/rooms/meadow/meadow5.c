#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadowwest";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow9",
     "east":MEADOW"meadow6",
     "south":MEADOW"meadow1",
     //"west":MEADOW"meadow3",
   ]));
}
