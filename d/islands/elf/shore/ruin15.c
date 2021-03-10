#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "south": ROOMS"shore/ruin10", 
   "north": ROOMS"shore/tower0", 
     ]));

}