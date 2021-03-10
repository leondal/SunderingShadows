//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "west": ROOMS"store",  
   "south": ROOMS"magic",
   "east": ROOMS"grandhall",   ]));
   set_door("door",ROOMS"magic","south","key");
   set_locked("door",0);
   set_door_description("door","This door is made of metal and quartz.");

}
