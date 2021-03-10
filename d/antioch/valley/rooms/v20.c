#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v19",
   "west" : ROOMS+"v21",
   "south" : ROOMS+"v2",
   "north" : ROOMS+"g2",
   ]) );
}
