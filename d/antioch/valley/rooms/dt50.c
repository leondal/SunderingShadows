#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt49",
   "northeast" : ROOMS+"dt51",
   ]) );
}
