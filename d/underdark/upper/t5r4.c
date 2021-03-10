#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "east":UPPER"t5r3",
      "southeast":UPPER"t5r7",
      "southwest":UPPER"t5r5",
    ])); 
}