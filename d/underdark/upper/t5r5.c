#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t5r4",
      "east":UPPER"t5r7",
      "southeast":UPPER"t5r6",
      "down":UPPER"t2r4",
    ])); 
}