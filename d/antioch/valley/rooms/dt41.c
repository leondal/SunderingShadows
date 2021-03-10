#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt40",
   "northeast" : ROOMS+"dt42",
   ]) );
}
