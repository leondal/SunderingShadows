#include <std.h> 
#include "../defs.h" 
inherit INH+"chasmpath"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"northwest":UPPER"chasm02",
// Eventually there will be a way down to the next level of the underdark
// located here.  However, for now, the path is closed off. 
   ])); 
}