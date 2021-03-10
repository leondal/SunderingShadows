#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   
   set_exits(([
    "northwest":FROAD+"18",
    "southeast":FROAD+"20",
   ]));

}
