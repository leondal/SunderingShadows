#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin10", 
   "south": ROOMS"shore/ruin26", 
     ]));

}