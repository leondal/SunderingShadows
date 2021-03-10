#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/water", 
   "south": ROOMS"shore/ruin2",
   "east" : ROOMS"/shore/ruin14",
     ]));

}