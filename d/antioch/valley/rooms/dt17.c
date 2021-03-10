#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_long(::query_long()+"%^RESET%^%^BLUE%^To the southeast"+
   " there seems to be a large %^GREEN%^tree%^RESET%^%^BLUE%^."
   );
   set_exits( ([
   "southeast" : ROOMS+"dtree",
   "north" : ROOMS+"dt16",
   ]) );
}
