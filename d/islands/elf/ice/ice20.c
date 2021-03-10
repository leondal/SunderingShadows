//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"ice5", 
                "northeast": ROOMS"ice21", 
         ]));

}