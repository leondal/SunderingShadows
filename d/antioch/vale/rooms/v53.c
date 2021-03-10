#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^Directly to the east is one of the"+
   " %^ORANGE%^huts%^GREEN%^ that are scattered about the "+
   "vale. To the northwest is a well worn trail.\n"
   );
   set("night long",query("night long")+"%^BLUE%^Directly east of you"+
   " is one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the vale. To the northwest is a well"+
   " worn trail.\n"
   );
   set_exits(([
   "west" : ROOMS+"v54",
   "south" : ROOMS+"c42",
   "north" : ROOMS+"v52",
   "northwest" : FPATH+"trail1",
   ]));
}
