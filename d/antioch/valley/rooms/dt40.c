#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt35",
   "north" : ROOMS+"dt41",
   ]) );
}
