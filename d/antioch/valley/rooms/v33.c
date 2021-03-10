#include <std.h>
#include "../valley.h"
inherit VALLEY;


void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"g90",
   "west" : ROOMS+"v34",
   "north" : ROOMS+"g86",
   "south" : ROOMS+"v32",
   ]) );
}
