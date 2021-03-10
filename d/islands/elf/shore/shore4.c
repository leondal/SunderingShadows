#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/shore5", 
     "west": ROOMS"shore/shore3",
	"northeast": ROOMS"ice/ice19",
     ]));

}