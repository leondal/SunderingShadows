#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"southeast":UPPER"tunnel30",
"east":UPPER"tunnel35",
"north":UPPER"tunnel37",
   ])); 
}