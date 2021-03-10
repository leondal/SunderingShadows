#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keepupper";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hall extends further to the south and east, "
"while the remnants of a once-grand %^RED%^staircase %^RESET%^lies to the "
"north.\n");
   set_exits(([
     "north" : ROOMS"stair2",
     "east" : ROOMS"floor2",
     "south" : ROOMS"floor3",
   ]));
   add_item("stair","%^RED%^To the north lies a crumbling staircase that leads "
"down to the base floor of the keep.%^RESET%^");
   add_item("stairs","%^RED%^To the north lies a crumbling staircase that leads "
"down to the base floor of the keep.%^RESET%^");
   add_item("staircase","%^RED%^To the north lies a crumbling staircase that "
"leads down to the base floor of the keep.%^RESET%^");
}
