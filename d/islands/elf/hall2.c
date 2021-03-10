//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "north": ROOMS"hall1",  
    "east": ROOMS"hgarden",  
   "south": ROOMS"hall3",   ]));


}
