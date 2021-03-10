//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "northwest": ROOMS"ice7", 
      "east": ROOMS"ice4",   
      "southeast": ROOMS"ice8",	  ]));

}