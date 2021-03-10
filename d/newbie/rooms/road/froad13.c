#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_exits(([
    "north":FROAD+"12",
    "south":FROAD+"14",
   ]));
}
