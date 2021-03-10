#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up into the town of Offestry directly "+
   "west of here or continues eastward.%^RESET%^");
   set_exits(([
    "west":MAINTOWN"estreet3",
    "east":FROAD+"5",
   ]));
}
