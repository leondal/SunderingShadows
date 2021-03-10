#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t5r2",
      "west":UPPER"t5r6",
      "northwest":UPPER"t5r7",
      "down":UPPER"t4r7",
    ])); 
}