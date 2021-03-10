#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "east": ROOMS"shore/ruin9", 
    "west": ROOMS"shore/ruin11", 
    "north": ROOMS"shore/ruin15", 
     ]));

}