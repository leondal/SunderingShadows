#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : ROOMS+"dt20",
   "southwest" : ROOMS+"dt22",
   ]) );
}
