#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt51",
   "northwest" : ROOMS+"dt53",
   ]) );
}
