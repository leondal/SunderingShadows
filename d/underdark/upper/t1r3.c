#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "southeast":UPPER"t1r2",
      "west":UPPER"t1r4",
      "southwest":UPPER"t1r7",
    ])); 
}