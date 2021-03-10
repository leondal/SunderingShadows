#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "east":UPPER"t2r3",
      "southeast":UPPER"t2r7",
      "southwest":UPPER"t2r5",
      "up":UPPER"t5r5",
    ])); 
}