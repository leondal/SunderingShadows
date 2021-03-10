#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_exits(([
    "east":FROAD+"8",
    "west":FROAD+"10",
   ]));
}
