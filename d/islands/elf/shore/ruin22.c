#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin21", 
   "west": ROOMS"shore/ruin23", 
   "south": ROOMS"shore/house4", 
     ]));

}