#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "southwest": ROOMS"shore/shore1", 
     "east": ROOMS"shore/shore3",
     ]));

}
