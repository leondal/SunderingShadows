#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t4r5",
      "northeast":UPPER"t4r7",
      "east":UPPER"t4r1",
      "down":UPPER"t1r6",
    ])); 
}