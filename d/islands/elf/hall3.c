//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "north": ROOMS"hall2",  
    "east": ROOMS"corridor",  
   "south": ROOMS"store",   ]));


}
