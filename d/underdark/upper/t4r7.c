#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t4r3",
      "east":UPPER"t4r2",
      "southeast":UPPER"t4r1",
      "southwest":UPPER"t4r6",
      "west":UPPER"t4r5",
      "northwest":UPPER"t4r4",
      "up":UPPER"t5r1",
    ])); 
}