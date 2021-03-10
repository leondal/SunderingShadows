#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t3r3",
      "west":UPPER"t3r7",
      "southwest":UPPER"t3r1",
    ])); 
}