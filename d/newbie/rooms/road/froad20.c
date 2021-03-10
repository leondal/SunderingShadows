#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail ends here at a %^BOLD%^%^BLACK%^"+
   "mine%^RESET%^%^GREEN%^ to the south or continues northward.%^RESET%^");
   
   set_exits(([
    "northwest":FROAD+"19",
    "south":HILL"mine1",
   ]));

}
