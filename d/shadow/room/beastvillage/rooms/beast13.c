#include <std.h> 
#include "../defs.h" 
inherit INH+"northbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"northwest":ROOMS"beast14",
"east":ROOMS"beast12",
"southwest":"/d/magic/temples/the_faceless_one/the_faceless_oneentry",
   ])); 
}
