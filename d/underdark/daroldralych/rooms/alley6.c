#include <std.h>
#include "../defs.h"
inherit INH+"alley";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  To the east, you can see where this street meets with one of the main thoroghfares of "
"the city.%^RESET%^\n");

   add_item(({"houses","buildings","walls"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably "
"belonging to mid-ranked houses judging by their appearance.  The enclosure to the north retains two buildings, one "
"smaller and with the appearance of living quarters, while the other is far larger.  You can't tell from here what would "
"be in the large building.  To the south is the rear of an enclosure of several short, %^RED%^stu%^ORANGE%^rd%^RED%^y "
"%^BLUE%^buildings, only one of which seems large enough to contain living quarters for a drow house.  From the others "
"echoes the %^RED%^lo%^BOLD%^u%^RESET%^%^RED%^d sound %^BLUE%^of metalworking.%^RESET%^");
   set_exits(([
     "west":ROOMS"alley5",
     "east":ROOMS"south3",
   ]));
}
