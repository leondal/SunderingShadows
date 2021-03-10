#include <std.h> 
#include "../defs.h" 
inherit INH+"northbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"northwest":ROOMS"beast10",
"southeast":ROOMS"beast08",
   ])); 
}