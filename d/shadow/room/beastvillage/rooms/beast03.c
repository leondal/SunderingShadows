#include <std.h> 
#include "../defs.h" 
inherit INH+"southbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n"); 
   set_exits(([ 
"north":ROOMS"beast04",
"south":ROOMS"beast02",
   ])); 
}