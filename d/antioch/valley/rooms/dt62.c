#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt61",
   "north" : ROOMS+"e1523",
   ]) );
   set_invis_exits(({"north"}));
}
