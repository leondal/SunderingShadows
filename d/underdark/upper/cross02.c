#include <std.h> 
#include "../defs.h" 
inherit INH+"crossroad"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"west":UPPER"cross01",
"east":UPPER"cross03",
   ])); 
}