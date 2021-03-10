#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  One of the warehouses south of the road looks to have been converted into a shop "
"of some kind.  Further to the east and west, the street continues to stretch along the edge of the warehouse "
"district.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the southern side of the road rise enclosed buildings, "
"obviously belonging to fairly %^RED%^h%^BOLD%^ig%^RESET%^%^RED%^h-ra%^BOLD%^nk%^RESET%^%^RED%^ed %^BLUE%^houses "
"by their extravagant architecture and style.  The house directly to the south strikes quite a contrast to most "
"others, as it seems more like a %^RED%^mili%^BOLD%^%^BLACK%^ta%^RESET%^%^RED%^ry com%^BOLD%^%^BLACK%^po%^RESET%^"
"%^RED%^und %^BLUE%^than anything else.  Its structure is far more rigid and sturdy than the usual grace of drow "
"crafting, and you can see many soldiers moving about the grounds.%^RESET%^");
   add_item("shop","%^BLUE%^Upon the southern side of the road it seems that one of the warehouses has been "
"converted into a small shop, with various simple items displayed behind barred %^CYAN%^g%^BOLD%^l%^RESET%^"
"%^CYAN%^ass %^BLUE%^windows.%^RESET%^");
   set_exits(([
     "west":ROOMS"dock5",
     "east":ROOMS"dock7",
     "south":ROOMS"general",
   ]));
}
