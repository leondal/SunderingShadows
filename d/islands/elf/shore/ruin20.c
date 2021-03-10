#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/ruin5", 
   "west": ROOMS"shore/ruin21", 
     ]));

}