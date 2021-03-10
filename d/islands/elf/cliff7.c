//cliff
#include <std.h>
#include "elf.h"
inherit INH"cliff";


void create(){
    ::create();

   set_exits(([ "west": ROOMS"grove8", 
   "northwest": ROOMS"cliff6", 
   "south": ROOMS"cliff8",   ]));


}