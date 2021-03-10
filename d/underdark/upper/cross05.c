#include <std.h> 
#include "../defs.h" 
inherit INH+"crossroad"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^RESET%^%^ORANGE%^A surface road passes over head here causing dust to "
"occasionally shift down from the ceiling making the passageway hazy and the air "
"thick and difficult to breathe.\n%^RESET%^"); 

add_item(({"dust","traffic"}),"%^RESET%^%^ORANGE%^An occasional shout or groan of an "
"over ladened wagon reaches your ears, even as dust sifts down from the ceiling, altering "
"you to the surface traffic above.%^RESET%^"); 

   set_exits(([ 
"northwest":UPPER"cross04",
"southeast":UPPER"cross06",
   ])); 
}