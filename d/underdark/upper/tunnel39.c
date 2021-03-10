#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"south":UPPER"tunnel32",
"west":UPPER"tunnel37",
   ])); 
}