#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the southeast is one of the"+
   " %^ORANGE%^huts%^GREEN%^ that are scattered about the vale. To the west is a better defined"+
   " trail that leads off to the north somewhere.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the southeast of"+
   " you is one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the vale. To the west is a"+
   " more well defined trail that leads off to the north somewhere.\n"
   );
   set_exits(([
   "south" : ROOMS+"v53",
   "east" : ROOMS+"v51",
   "west" : FPATH+"trail1",
   ]));
}
