#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t5r3",
      "east":UPPER"t5r2",
      "southeast":UPPER"t5r1",
      "southwest":UPPER"t5r6",
      "west":UPPER"t5r5",
      "northwest":UPPER"t5r4",
    ])); 
}