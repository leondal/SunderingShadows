#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t2r2",
      "west":UPPER"t2r6",
      "northwest":UPPER"t2r7"
    ])); 
}