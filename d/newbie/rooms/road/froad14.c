#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
    set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail splits here to the south "+
   "or continues northward.%^RESET%^");
   set_exits(([
    "north":FROAD+"13",
    "southwest":FROAD+"15",
    "southeast":FROAD+"18",
   ]));
}
