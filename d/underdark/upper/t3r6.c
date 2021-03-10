#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northwest":UPPER"t3r5",
      "northeast":UPPER"t3r7",
      "east":UPPER"t3r1",
    ])); 
}