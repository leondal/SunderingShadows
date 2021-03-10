#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "south": ROOMS"shore/ruin25", 
   "north": ROOMS"shore/ruin11", 
   "east": ROOMS"shore/house5", 
     ]));

}