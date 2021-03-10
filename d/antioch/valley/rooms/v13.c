#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v12",
   "west" : ROOMS+"v14",
   "south" : ROOMS+"v9",
   "north" : ROOMS+"g9",
   ]) );
}
