#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt9",
   "northwest" : ROOMS+"dt11",
   ]) );
}
