#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : ROOMS+"dt13",
   "south" : ROOMS+"dt17",
   "west" : ROOMS+"dt19",
   ]) );
}
