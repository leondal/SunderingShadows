#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"shore/ruin6", 
    "south": ROOMS"shore/ruin12", 
    "east": ROOMS"shore/ruin13", 
     ]));

}