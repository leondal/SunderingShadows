#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt20",
   "west" : ROOMS+"dt24",
   ]) );
}
