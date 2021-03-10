#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/flow2", 
   "south": ROOMS"shore/flow7",
     ]));

}