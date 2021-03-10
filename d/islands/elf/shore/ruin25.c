#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "south": ROOMS"shore/ruin24", 
   "north": ROOMS"shore/ruin26", 
     ]));

}