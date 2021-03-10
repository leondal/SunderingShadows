#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall";

void create(){ 
   ::create();
   set_long(::query_long() +"  To the north is a %^RED%^staircase %^RESET%^that "
"appears to lead to a floor above this one.  East leads towards the back of the "
"keep, with the barracks and servants' quarters.\n");
   set_exits(([
     "east" : ROOMS"keep12",
     "west" : ROOMS"keep10",
     "north" : ROOMS"stair1",
   ]));
   add_item("stair","%^RED%^An old spiral staircase lies just off to the side "
"of this hallway, leading upwards to the second floor of the keep.%^RESET%^");
   add_item("stairs","%^RED%^An old spiral staircase lies just off to the side "
"of this hallway, leading upwards to the second floor of the keep.%^RESET%^");
   add_item("staircase","%^RED%^An old spiral staircase lies just off to the "
"side of this hallway, leading upwards to the second floor of the "
"keep.%^RESET%^");
}
