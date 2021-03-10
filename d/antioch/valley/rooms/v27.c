#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"g23",
   "west" : ROOMS+"v28",
   "north" : ROOMS+"g121",
   "south" : ROOMS+"v26",
   ]) );
}
