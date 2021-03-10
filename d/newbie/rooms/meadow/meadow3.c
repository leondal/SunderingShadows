#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadowsouth";

void create()
{
   ::create();
   set_exits(([
     "north":MEADOW"meadow7",
     "east":MEADOW"meadow4",
     //"south":MEADOW,
     "west":MEADOW"meadow2",
   ]));
}
