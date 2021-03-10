//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"ice10", 
      "west": ROOMS"ice8",    ]));

}