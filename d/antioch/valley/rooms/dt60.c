#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"dt59",
   "northwest" : ROOMS+"dt61",
   ]) );
}
