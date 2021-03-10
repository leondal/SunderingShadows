#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t1r3",
      "east":UPPER"t1r2",
      "southeast":UPPER"t1r1",
      "southwest":UPPER"t1r6",
      "west":UPPER"t1r5",
      "northwest":UPPER"t1r4",
    ])); 
}