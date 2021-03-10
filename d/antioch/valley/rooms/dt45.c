#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"dt44",
   ]) );
}
