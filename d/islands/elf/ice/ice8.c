//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "northwest": ROOMS"ice6", 
      "east": ROOMS"ice9",    ]));

}