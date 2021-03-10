#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin22", 
   "west": ROOMS"shore/ruin24", 
     ]));

}