#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t4r3",
      "west":UPPER"t4r7",
      "southwest":UPPER"t4r1",
      "down":UPPER"t3r7",
    ])); 
}