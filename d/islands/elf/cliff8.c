//cliff
#include <std.h>
#include "elf.h"
inherit INH"cliff";


void create(){
    ::create();

   set_exits(([ "west": ROOMS"grove6",  
    "north": ROOMS"cliff7",
    "south": ROOMS"cliff1", 	]));


}