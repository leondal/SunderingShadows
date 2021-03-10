//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "north": ROOMS"hall5",  
    "west": ROOMS"corridor",  
	 "east": ROOMS"lab",  
   "south": ROOMS"grandhall",   ]));

  set_door("door",ROOMS"lab","east",0,0);
   set_door_description("door","The door appears to be made of a bright strange metal.");
}
