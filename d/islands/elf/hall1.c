//cliff
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "north": ROOMS"inn",  
   "south": ROOMS"hall2",   ]));


}
