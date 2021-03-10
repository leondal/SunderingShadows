#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt53",
   "northeast" : ROOMS+"dt55",
   ]) );
}
