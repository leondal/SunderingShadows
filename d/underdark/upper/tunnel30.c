#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"east":UPPER"tunnel29",
"northwest":UPPER"tunnel34",
"west":UPPER"tunnel31",
   ])); 
}