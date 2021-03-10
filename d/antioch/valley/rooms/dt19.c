#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"dt16",
   "southwest" : ROOMS+"dt20",
   ]) );
}
