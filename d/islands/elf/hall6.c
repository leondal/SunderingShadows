//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "north": ROOMS"library",  
   "south": ROOMS"hall5",   ]));


}
