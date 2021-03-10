#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t2r5",
      "northeast":UPPER"t2r7",
      "east":UPPER"t2r1",
      "down":UPPER"t1r5",
    ])); 
}