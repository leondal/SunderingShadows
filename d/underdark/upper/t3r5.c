#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t3r4",
      "east":UPPER"t3r7",
      "southeast":UPPER"t3r6",
      "down":UPPER"t2r2",
    ])); 
}