//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"ice3", 
                "east": ROOMS"ice20", 
         ]));

}