#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : ROOMS+"dt6",
   "southwest" : ROOMS+"dt4",
   "southeast" : ROOMS+"dt26",
   ]) );
}
