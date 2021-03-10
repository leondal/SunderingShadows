#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : "/d/antioch/wild/forest/trail6",
   "northeast" : ROOMS+"dt2",
   ]) );
}
