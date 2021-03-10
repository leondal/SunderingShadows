#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v20",
   "west" : ROOMS+"v22",
   "south" : ROOMS+"v1",
   "north" : ROOMS+"g1",
   ]) );
}
