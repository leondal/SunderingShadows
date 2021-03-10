#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "east":UPPER"t4r3",
      "southeast":UPPER"t4r7",
      "southwest":UPPER"t4r5",
      "down":UPPER"t2r3",
    ])); 
}