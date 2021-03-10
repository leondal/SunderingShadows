#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hallway leads off from this point to the "
"south and east.  Southwards, you can see several rooms opening off the main "
"corridor, while to the east a %^RED%^staircase %^RESET%^is visible.\n");
   set_exits(([
     "east" : ROOMS"keep11",
     "south" : ROOMS"keep9",
   ]));
   add_item("stair","%^RED%^An old spiral staircase lies ahead to the east, "
"leading upwards.%^RESET%^");
   add_item("stairs","%^RED%^An old spiral staircase lies ahead to the east, "
"leading upwards.%^RESET%^");
   add_item("staircase","%^RED%^An old spiral staircase lies ahead to the east, "
"leading upwards.%^RESET%^");
}
