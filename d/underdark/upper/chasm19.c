#include <std.h> 
#include "../defs.h" 
inherit INH+"chasmpath"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^RESET%^%^RED%^The chasm ends here, narrowing to a point where you "
"could easily step across to where a narrow crack in the wall hints that there "
"might be something further to explore.%^RESET%^\n"); 

   add_item(({"crack","wall"}),"%^RESET%^%^RED%^It looks like you might be able to "
"wiggle through the crack into a hidden room.%^RESET%^"); 

   set_exits(([ 
"crack":UPPER"portal",
"south":UPPER"chasm18",
   ])); 
}