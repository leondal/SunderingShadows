#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/flow3", 
   "south": ROOMS"shore/flow8",
   "north": ROOMS"shore/flow6",
     ]));

}