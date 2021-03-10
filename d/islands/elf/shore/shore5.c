#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/shore6", 
     "west": ROOMS"shore/shore4",
	"north": ROOMS"ice/ice19",
     ]));

}