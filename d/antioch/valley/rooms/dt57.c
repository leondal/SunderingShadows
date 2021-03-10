#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt53",
   "west" : ROOMS+"dt58",
   ]) );
}
