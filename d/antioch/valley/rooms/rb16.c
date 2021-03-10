#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"shore3",
   "east" : ROOMS+"shore4",
   "south" : ROOMS+"v51",
   ]) );
}
