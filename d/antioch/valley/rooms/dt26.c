#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"dt5",
   "south" : ROOMS+"dt27",
   ]) );
}
