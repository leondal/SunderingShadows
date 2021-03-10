#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/flow8", 
 
   "east": ROOMS"shore/flow5",
     ]));

}