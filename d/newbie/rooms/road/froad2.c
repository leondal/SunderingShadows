#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_exits(([
    "south":FROAD+"1",
    "northeast":FROAD+"3",
   ]));
}
