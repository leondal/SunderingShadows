#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t2r3",
      "east":UPPER"t2r2",
      "southeast":UPPER"t2r1",
      "southwest":UPPER"t2r6",
      "west":UPPER"t2r5",
      "northwest":UPPER"t2r4",
      "down":UPPER"t1r4",
    ])); 
}