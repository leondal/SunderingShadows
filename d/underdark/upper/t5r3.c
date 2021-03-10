#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "southeast":UPPER"t5r2",
      "west":UPPER"t5r4",
      "southwest":UPPER"t5r7",
    ])); 
}