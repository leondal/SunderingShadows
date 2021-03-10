//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "northeast": ROOMS"ice3", 
      "west": ROOMS"ice6",    ]));

}