#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t4r4",
      "east":UPPER"t4r7",
      "southeast":UPPER"t4r6",
      "up":UPPER"t5r6",
    ])); 
}