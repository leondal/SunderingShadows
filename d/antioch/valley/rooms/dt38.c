#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : ROOMS+"dt37",
   ]) );
}
