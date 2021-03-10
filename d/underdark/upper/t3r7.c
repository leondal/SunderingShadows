#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t3r3",
      "east":UPPER"t3r2",
      "southeast":UPPER"t3r1",
      "southwest":UPPER"t3r6",
      "west":UPPER"t3r5",
      "northwest":UPPER"t3r4",
      "up":UPPER"t4r2",
    ])); 
}