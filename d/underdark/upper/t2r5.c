#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t2r4",
      "east":UPPER"t2r7",
      "southeast":UPPER"t2r6",
    ])); 
}