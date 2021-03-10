#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/flow4", 
   "south": ROOMS"shore/flow9",
   "north": ROOMS"shore/flow7",
     ]));

}