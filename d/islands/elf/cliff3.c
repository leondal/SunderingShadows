//cliff
#include <std.h>
#include "elf.h"
inherit INH"cliff";


void create(){
    ::create();

   set_exits(([ "east": ROOMS"grove5",  
  "south": ROOMS"cliff2",
  "up": ROOMS"quest",
  "northeast": ROOMS"cliff4",   ]));


}