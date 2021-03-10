#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"south":UPPER"tunnel28",
"north":UPPER"tunnel35",
"northwest":UPPER"tunnel37",
"west":UPPER"tunnel30",
   ])); 
}