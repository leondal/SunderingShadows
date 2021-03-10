#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin20", 
   "west": ROOMS"shore/ruin22", 
     ]));

}