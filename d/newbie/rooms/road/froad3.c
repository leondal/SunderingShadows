#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up into an overgrown meadow directly north of "+
   "here or continues southward.%^RESET%^");
   set_exits(([
    "north":MEADOWR"meadow2",
    "southwest":FROAD+"2",
   ]));
}
