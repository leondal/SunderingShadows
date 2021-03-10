#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/ruin3", 
   "south": ROOMS"/shore/ruin5",
   "east": ROOMS"/shore/ruin6",
     ]));

}