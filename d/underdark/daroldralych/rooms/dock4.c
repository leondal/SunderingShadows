#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  Further to the east and west, this main roadway continues along the edge of "
"the warehouse district, while to the southeast you can see the city square.  Off to the roadside, a small alley "
"weaves away between the buildings.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the southern side of the road rise enclosed buildings, "
"obviously belonging to fairly %^RED%^h%^BOLD%^ig%^RESET%^%^RED%^h-ra%^BOLD%^nk%^RESET%^%^RED%^ed %^BLUE%^houses "
"by their extravagant architecture and style.  The buildings directly to the west are somewhat similar to what "
"you can see on the northern side of the road.  Inside the fences can be seen a myriad of smaller buildings, with "
"various drow going to and fro conveying a variety of items.  Within the centre is a little complex that probably "
"serves as the living quarters, and despite its uncommonly small size for a noble house, it still carries the "
"particularly %^MAGENTA%^ex%^CYAN%^tr%^MAGENTA%^ava%^CYAN%^g%^MAGENTA%^ant %^BLUE%^architecture of the upper-class "
"houses.%^RESET%^");
   add_item(({"alleys","alley","small alleys"}),"%^BLUE%^At the side of the road a small alleyway splits "
"away from the main street and winds off into %^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^ar%^BOLD%^%^BLACK%^kn%^RESET%^"
"%^BLUE%^es%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^ between the houses.%^RESET%^");
   set_exits(([
     "northwest":ROOMS"dock3",
     "northeast":ROOMS"dock5",
     "southwest":ROOMS"alley1",
     "southeast":ROOMS"northwest1",
   ]));
}
