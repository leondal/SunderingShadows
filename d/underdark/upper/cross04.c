#include <std.h> 
#include "../defs.h" 
inherit INH+"crossroad"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"northwest":UPPER"cross03",
"southeast":UPPER"cross05",
   ])); 
}