#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt1",
   "northeast" : ROOMS+"dt3",
   ]) );
}
