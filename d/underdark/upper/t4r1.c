#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_exits(([ 
      "northeast":UPPER"t4r2",
      "west":UPPER"t4r6",
      "northwest":UPPER"t4r7"
    ])); 
}