#include <std.h> 
#include "../defs.h" 
inherit INH+"crossroad"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"southwest":UPPER"cross11",
"northeast":UPPER"cross13",
   ])); 
}