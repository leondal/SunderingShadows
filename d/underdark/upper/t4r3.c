#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "southeast":UPPER"t4r2",
      "west":UPPER"t4r4",
      "southwest":UPPER"t4r7",
      "down":UPPER"t3r4",
    ])); 
}