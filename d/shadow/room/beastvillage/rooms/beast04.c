#include <std.h> 
#include "../defs.h" 
inherit INH+"southbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"northeast":ROOMS"beast05",
"south":ROOMS"beast03",
   ])); 
}