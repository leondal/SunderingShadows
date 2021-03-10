#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "southeast":UPPER"t3r2",
      "west":UPPER"t3r4",
      "southwest":UPPER"t3r7",
    ])); 
}