#include <std.h>
#include "../defs.h"
inherit INH+"alley";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  To the north, you can see where this street meets with one of the main thoroghfares "
"of the city.%^RESET%^\n");

   add_item(({"houses","buildings","walls"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably "
"belonging to mid-ranked houses judging by their appearance.  To the west is quite a small house, particularly %^MAGENTA%^"
"gr%^RED%^ac%^MAGENTA%^ef%^RED%^ul %^BLUE%^in its design, but almost to the point of fragility.  East rises the rear of a "
"complex that consists of several sections, designed more in %^CYAN%^sim%^GREEN%^pl%^CYAN%^e eleg%^GREEN%^a%^CYAN%^nce "
"%^BLUE%^than the extravagance of the upper houses, and with only a token display of guardian force.%^RESET%^");
   set_exits(([
     "north":ROOMS"west3",
     "south":ROOMS"alley4",
   ]));
}
