#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/ruin1", 
   "south": ROOMS"/shore/ruin3",
   
     ]));

}