#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"east":UPPER"tunnel32",
"northeast":UPPER"tunnel40",
   ])); 
}