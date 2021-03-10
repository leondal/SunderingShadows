#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadowsoutheast";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow8",
     //"east":MEADOW"meadow4",
     //"south":MEADOW,
     "west":MEADOW"meadow3",
   ]));
}
