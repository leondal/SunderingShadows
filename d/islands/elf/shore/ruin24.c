#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin23", 
   "north": ROOMS"shore/ruin25", 
     ]));

}