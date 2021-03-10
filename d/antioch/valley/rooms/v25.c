#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"g23",
   "east" : ROOMS+"g22",
   "west" : ROOMS+"v26",
   "south" : ROOMS+"v24",
   ]) );
}
