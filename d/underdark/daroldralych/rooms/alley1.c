#include <std.h>
#include "../defs.h"
inherit INH+"alley";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  To the northeast, you can see where this street opens out to the warehouse "
"district.%^RESET%^\n");

   add_item(({"houses","buildings","walls"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, obviously "
"belonging to very high-ranked houses by their extravagant architecture and style.  The building to the east is possibly "
"the most %^MAGENTA%^la%^RED%^vi%^MAGENTA%^sh %^BLUE%^you have seen in the entire city, although you can't see all its "
"features from here.  To the west is the back of a large, round-shaped building of grand size, showing a faint glow of "
"%^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ around its edges that is too distant to light the street you "
"stand upon.%^RESET%^");
   set_exits(([
     "northeast":ROOMS"dock4",
     "south":ROOMS"alley2",
   ]));
}
