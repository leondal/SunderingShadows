#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/flow2", 
   "south": ROOMS"shore/flow4",
   "west": ROOMS"shore/flow7",
     ]));

}