#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up into the town of Offestry directly "+
   "east of here or continues westward.%^RESET%^");
   set_exits(([
    "east":MAINTOWN"wstreet3",
    "west":FROAD+"9",
   ]));
}
