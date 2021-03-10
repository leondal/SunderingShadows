#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt41",
   "southeast" : ROOMS+"dt43",
   ]) );
}
