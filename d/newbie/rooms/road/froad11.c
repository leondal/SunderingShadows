#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail meets another well-trodden one "+
   "in front of a large keep directly northwest or continues eastward.%^RESET%^");
   set_exits(([
    "northwest":KEEP"path4",
    "east":FROAD+"10",
   ]));
}
