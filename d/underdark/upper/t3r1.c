#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t3r2",
      "west":UPPER"t3r6",
      "northwest":UPPER"t3r7",
      "down":UPPER"t1r2",
    ])); 
}