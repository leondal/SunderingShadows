#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v14",
   "west" : ROOMS+"v16",
   "south" : ROOMS+"v7",
   "north" : ROOMS+"g7",
   ]) );
}
