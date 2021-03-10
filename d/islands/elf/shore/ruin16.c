#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "south": ROOMS"shore/ruin13", 
   "north": ROOMS"shore/ruin19", 


     ]));

}