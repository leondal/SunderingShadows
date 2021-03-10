#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t5r5",
      "northeast":UPPER"t5r7",
      "east":UPPER"t5r1",
      "down":UPPER"t4r5",
    ])); 
}