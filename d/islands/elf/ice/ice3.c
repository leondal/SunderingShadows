//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"ice2", 
      "east": ROOMS"ice5",   
      "southwest": ROOMS"ice4",	  ]));

}