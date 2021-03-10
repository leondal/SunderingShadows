#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/shore4", 
     "west": ROOMS"shore/shore2",
	
     ]));

}
