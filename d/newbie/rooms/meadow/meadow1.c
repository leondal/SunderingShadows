#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadowsouthwest";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow5",
     "east":MEADOW"meadow2",
     //"south":MEADOW,
     //"west":GRAVEYARD"cemetery4",
   ]));
}
