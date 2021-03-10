#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t1r5",
      "northeast":UPPER"t1r7",
      "east":UPPER"t1r1",
      "up":UPPER"t4r6",
    ])); 
}