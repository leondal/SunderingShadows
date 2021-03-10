//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"ice1", 
      "east": ROOMS"ice3",    ]));

}