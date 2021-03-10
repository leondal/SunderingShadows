#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"southeast":UPPER"tunnel27",
"north":UPPER"tunnel29",
   ])); 
}