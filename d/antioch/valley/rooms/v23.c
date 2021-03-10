#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"v22",
   "west" : ROOMS+"v24",
   "north" : ROOMS+"g22",
   "east" : ROOMS+"g1",
   ]) );
}
