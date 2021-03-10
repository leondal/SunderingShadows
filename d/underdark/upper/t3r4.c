#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "east":UPPER"t3r3",
      "southeast":UPPER"t3r7",
      "southwest":UPPER"t3r5",
      "up":UPPER"t4r3",
    ])); 
}