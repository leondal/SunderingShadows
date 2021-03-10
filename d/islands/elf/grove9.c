//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([ "south" : ROOMS"gate1",
    "north": ROOMS"grove1",  
    ]));


}
