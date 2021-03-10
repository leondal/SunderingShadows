#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"g90",
   "east" : ROOMS+"g93",
   "west" : ROOMS+"v32",
   "south" : ROOMS+"v30",
   ]) );
}
