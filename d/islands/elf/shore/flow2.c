#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/flow1", 
   "south": ROOMS"shore/flow3",
   "west": ROOMS"shore/flow6",
     ]));

}