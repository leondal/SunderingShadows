#include <std.h> 
#include "../defs.h" 
inherit INH+"southbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n"); 
   set_exits(([ 
"north":ROOMS"beast03",
"south":ROOMS"beast01",
   ])); 
}