//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "northwest": ROOMS"ice18", 
     "southwest": ROOMIE"/shore/shore4", 
     "south": ROOMIE"/shore/shore5", 
      ]));

}