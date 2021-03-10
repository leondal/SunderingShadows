#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v7",
   "east" : ROOMS+"v9",
   "north" : ROOMS+"v14",
   "south" : ROOMS+"e1519",
    ]) );
   set_invis_exits(({"south"}));
}
