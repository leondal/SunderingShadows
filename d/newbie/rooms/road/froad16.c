#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   
   set_exits(([
    "northeast":FROAD+"15",
    "southwest":FROAD+"17",
   ]));

}
