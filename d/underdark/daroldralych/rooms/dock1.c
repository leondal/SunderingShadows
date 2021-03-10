#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLUE%^Warehouse district%^RESET%^\n"
"%^BLUE%^The road widens here, turning to run along beside the edge of the great %^BOLD%^black lake "
"%^RESET%^%^BLUE%^to the north.  Smooth stone forms the ground beneath your feet, allowing for ease in "
"walking.  Only %^BLACK%^%^BOLD%^d%^RESET%^%^BLUE%^ar%^BOLD%^%^BLACK%^kn%^RESET%^%^BLUE%^es%^BOLD%^%^BLACK%^s "
"%^RESET%^%^BLUE%^fills the air above you, the ceiling too high up to be seen by any form of normal vision.  "
"Upon the northern side of the road are collected numerous %^ORANGE%^wa%^RED%^re%^ORANGE%^ho%^RED%^us%^ORANGE%^es"
"%^BLUE%^, some tightly closed while others are obviously in the middle of a bustling business.  At short "
"intervals along the southern side of the street are slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si"
"%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^"
"%^MAGENTA%^ie fire %^BLUE%^that sheds faint light around it.  To the south this street narrows and leads away "
"along the side of the vast cavern, while to the east it travels further into the warehouse district.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the southern side of the road rise enclosed buildings, "
"obviously belonging to fairly %^RED%^h%^BOLD%^ig%^RESET%^%^RED%^h-ra%^BOLD%^nk%^RESET%^%^RED%^ed %^BLUE%^houses "
"by their extravagant architecture and style.  The buildings directly to the south are somewhat similar to what "
"you can see on the northern side of the road.  Inside the fences can be seen a myriad of smaller buildings, with "
"various drow going to and fro conveying a variety of items.  Within the centre is a little complex that probably "
"serves as the living quarters, and despite its uncommonly small size for a noble house, it still carries the "
"particularly %^MAGENTA%^ex%^CYAN%^tr%^MAGENTA%^ava%^CYAN%^g%^MAGENTA%^ant %^BLUE%^architecture of the upper-class "
"houses.%^RESET%^");
   set_exits(([
     "south":ROOMS"outer1",
     "east":ROOMS"dock2",
   ]));
}
