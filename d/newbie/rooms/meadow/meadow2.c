#include <std.h>
#include "meadow.h"
inherit MEADOWI"meadowsouth";

void create()
{
   ::create();
   set_long(TO->query_long() + "%^BOLD%^%^GREEN%^  A trail opens up through the "+
   "otherwise impassable forest to the south.%^RESET%^");
   add_item(({"trail", "forest", "thick forest"}), "%^RESET%^%^GREEN%^A trail here opens up through "+
   "the otherwise impassable dark and forboding forest to the south. It looks as if it is well-kept.%^RESET%^");
   set_exits(([
     "north":MEADOW"meadow6",     
     "east":MEADOW"meadow3",
     "south":ROAD"froad3",
     "west":MEADOW"meadow1",
   ]));
}
