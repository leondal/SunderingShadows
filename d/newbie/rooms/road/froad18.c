#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   
   set_exits(([
    "northwest":FROAD+"14",
    "southeast":FROAD+"19",
   ]));

}
