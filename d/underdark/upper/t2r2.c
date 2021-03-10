#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t2r3",
      "west":UPPER"t2r7",
      "southwest":UPPER"t2r1",
      "up":UPPER"t3r5",
    ])); 
}