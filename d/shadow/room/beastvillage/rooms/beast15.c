#include <std.h> 
#include "../defs.h" 
inherit INH+"northbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"northeast":ROOMS"beast16",
"south":ROOMS"beast14",
   ])); 
}