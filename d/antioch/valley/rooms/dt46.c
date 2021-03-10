#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"dt44",
   "north" : ROOMS+"dt49",
   "southeast" : ROOMS+"dt47",
   ]) );
}
