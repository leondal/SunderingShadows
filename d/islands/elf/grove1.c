//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([ "south" : ROOMS"grove9",
    "north": ROOMS"grove4",  
    "west" : ROOMS"grove2",
    "east": ROOMS"grove3",  	]));


}

void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone1")->move(TO);
}
