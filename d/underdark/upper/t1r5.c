#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t1r4",
      "east":UPPER"t1r7",
      "southeast":UPPER"t1r6",
      "up":UPPER"t2r2",
    ])); 
}