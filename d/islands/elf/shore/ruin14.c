#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"shore/ruin1", 
   "east": ROOMS"shore/ruin17",
   "north": ROOMS"shore/house1",

     ]));

}