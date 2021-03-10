#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"dt7",
   "north" : ROOMS+"dt9",
   ]) );
}
