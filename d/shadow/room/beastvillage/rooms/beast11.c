#include <std.h> 
#include "../defs.h" 
inherit INH+"northbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"west":ROOMS"beast12",
"southeast":ROOMS"beast10",
   ])); 
}