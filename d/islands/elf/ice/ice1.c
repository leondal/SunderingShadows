//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "north": ROOMIE"/gate", 
      "south": ROOMS"ice2",    ]));

}