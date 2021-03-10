#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_long(::query_long()+"%^BLUE%^To the north seems"+
   " to be the entrance to some sort of %^BOLD%^%^GREEN%^valley%^RESET%^%^BLUE%^.\n"
   );
   set_exits( ([
   "south" : ROOMS+"dt14",
   "north" : ROOMS+"entrance",
   ]) );
}
