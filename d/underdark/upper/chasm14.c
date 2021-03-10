#include <std.h> 
#include "../defs.h" 
inherit INH+"chasmpath"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^RESET%^%^RED%^The top of a large %^ORANGE%^oak "
"tree %^RED%^rests on the ledge here, the wide thick branches creating a strong "
"base for this impromptu bridge that rises to the surface where the roots still "
"cling to the soil.%^RESET%^\n"); 

   add_item(({"tree","oak","branches","roots","bridge"}),"%^RESET%^%^ORANGE%^The "
"remains of a large oak tree have formed a ledge that leads from the surface down "
"to one of the wider sections of the rift's ledge. The heavy branches seem to have "
"braced the tree in place, while the thickly gnarled roots continue to cling to "
"the surface above.%^RESET%^"); 

   set_exits(([ 
"northwest":UPPER"chasm15",
"south":UPPER"chasm13",
"up":"/d/shadow/room/beastvillage/rooms/beast01",
   ])); 
}