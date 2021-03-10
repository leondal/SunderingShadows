#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t1r3",
      "west":UPPER"t1r7",
      "southwest":UPPER"t1r1",
      "up":UPPER"t3r1",
    ])); 
}