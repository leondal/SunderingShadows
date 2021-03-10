//cliff
#include <std.h>
#include "elf.h"
inherit INH"cliff";


void create(){
    ::create();

   set_exits(([ 
        "up": ROOMS"train",
        "east": ROOMS"grove7",  
        "south": ROOMS"grove5", 
        "northeast": ROOMS"cliff5",  
		"southwest": ROOMS"cliff3",]));


}
