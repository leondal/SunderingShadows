#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  Further to the east and west, the street continues to stretch along "
"the edge of the warehouse district.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the southern side of the road rise enclosed buildings, "
"obviously belonging to fairly %^RED%^h%^BOLD%^ig%^RESET%^%^RED%^h-ra%^BOLD%^nk%^RESET%^%^RED%^ed %^BLUE%^houses "
"by their extravagant architecture and style.  The house directly to the south strikes quite a contrast to most "
"others, as it seems more like a %^RED%^mili%^BOLD%^%^BLACK%^ta%^RESET%^%^RED%^ry com%^BOLD%^%^BLACK%^po%^RESET%^"
"%^RED%^und %^BLUE%^than anything else.  Its structure is far more rigid and sturdy than the usual grace of drow "
"crafting, and you can see many soldiers moving about the grounds.%^RESET%^");
   set_exits(([
     "west":ROOMS"dock6",
     "east":ROOMS"dock8",
   ]));
}
