#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/flow3", 
   "south": ROOMS"shore/flow5",
   "west": ROOMS"shore/flow8",
     ]));

}