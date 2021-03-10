//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "southeast": ROOMS"ice19", 
      "west": ROOMS"ice17",    ]));

}