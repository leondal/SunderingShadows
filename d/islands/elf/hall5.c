//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "north": ROOMS"hall6",  
    "west": ROOMS"hgarden",  
   "south": ROOMS"hall4", 
   "east": ROOMS"comps", ]));
   set_door("door",ROOMS"comps","east","key");
   set_locked("door",0);
   set_door_description("door","This door is made of metal and quartz.");

}
