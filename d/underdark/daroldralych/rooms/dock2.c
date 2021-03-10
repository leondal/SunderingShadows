#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  Further to the east and west, the street continues to stretch along the "
"edge of the warehouse district.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the southern side of the road rise enclosed buildings, "
"obviously belonging to fairly %^RED%^h%^BOLD%^ig%^RESET%^%^RED%^h-ra%^BOLD%^nk%^RESET%^%^RED%^ed %^BLUE%^houses "
"by their extravagant architecture and style.  The buildings directly to the south are somewhat similar to what "
"you can see on the northern side of the road.  Inside the fences can be seen a myriad of smaller buildings, with "
"various drow going to and fro conveying a variety of items.  Within the centre is a little complex that probably "
"serves as the living quarters, and despite its uncommonly small size for a noble house, it still carries the "
"particularly %^MAGENTA%^ex%^CYAN%^tr%^MAGENTA%^ava%^CYAN%^g%^MAGENTA%^ant %^BLUE%^architecture of the upper-class "
"houses.%^RESET%^");
   set_exits(([
     "west":ROOMS"dock1",
     "east":ROOMS"dock3",
   ]));
}
