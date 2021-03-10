#include "../valley.h"
inherit DTRAIL;


void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt33",
   "northeast" : ROOMS+"dt35",
   ]) );
}
