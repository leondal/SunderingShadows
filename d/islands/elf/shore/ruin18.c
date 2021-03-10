#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"shore/ruin17", 
    "south": ROOMS"shore/ruin19",
    "south": ROOMS"shore/house2",

     ]));

}