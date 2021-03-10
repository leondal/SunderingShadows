#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "southeast":UPPER"t2r2",
      "west":UPPER"t2r4",
      "southwest":UPPER"t2r7",
      "up":UPPER"t4r4",
    ])); 
}