#include <std.h> 
#include "../defs.h" 
inherit INH+"beastshore"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"north":ROOMS"beast07",
"southwest":ROOMS"beast05",
   ])); 
}