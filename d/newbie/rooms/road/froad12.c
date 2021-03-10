#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up into the town of Offestry directly "+
   "north of here or continues southward.%^RESET%^");
   set_exits(([
    "north":MAINTOWN"sstreet3",
    "south":FROAD+"13",
   ]));
}
