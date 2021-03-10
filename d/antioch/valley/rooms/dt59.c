#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt58",
   "west" : ROOMS+"dt60",
   ]) );
}
