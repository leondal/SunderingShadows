//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "northeast": ROOMS"ice11", 
      "east": ROOMS"ice13",    ]));

}