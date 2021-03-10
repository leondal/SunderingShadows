#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin3", 
   "west": ROOMS"/shore/ruin9",
     ]));

}