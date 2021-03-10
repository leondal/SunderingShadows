//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "southwest": ROOMS"ice23", 
                "northeast": ROOMS"ice25", 
         ]));

}