#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_exits(([
    "west":FROAD+"5",
    "east":FROAD+"7",
   ]));
}
