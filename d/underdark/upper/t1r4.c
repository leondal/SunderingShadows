#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft";  

void create(){ 
    ::create(); 
    set_exits(([ 
      "east":UPPER"t1r3",
      "southeast":UPPER"t1r7",
      "southwest":UPPER"t1r5",
      "up":UPPER"t2r7",
    ])); 
}