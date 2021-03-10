//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"ice17", 
      "west": ROOMS"ice15",    ]));

}