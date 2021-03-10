#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "west": ROOMS"shore/ruin14", 
    "east": ROOMS"shore/ruin18",

     ]));

}