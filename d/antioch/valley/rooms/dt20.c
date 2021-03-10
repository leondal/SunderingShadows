#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : ROOMS+"dt19",
   "southwest" : ROOMS+"dt21",
   "northwest" : ROOMS+"dt23",
   ]) );
}
