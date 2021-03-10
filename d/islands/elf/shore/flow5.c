#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/flow4", 
   "west": ROOMS"shore/flow9", 
   "east": ROOMS"shore/flow10", 
     ]));

}