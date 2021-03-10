#include <std.h> 
#include "../defs.h" 
inherit INH+"beastshore"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^BOLD%^%^WHITE%^A few %^RESET%^%^GREEN%^"
"vines %^BOLD%^%^WHITE%^grow at the edge of the water and hang down to a "
"landing somewhat further down the cliff.  You're not sure but if you were "
"good at climbing you might be able to make it down there.\n%^RESET%^"); 

add_item(({"vines","landing"}),"%^RESET%^%^ORANGE%^About halfway down the "
"the waterfall you can see a place where an outcropping of rocks has made "
"a secure landing.  Vines hang down the side of the wall, allowing someone "
"skilled at climbing to reach that ledge.%^RESET%^"); 

   set_exits(([ 
"northwest":ROOMS"beast09",
"south":ROOMS"beast07",
   ])); 

   set_climb_exits((["descend":({ROOMS"valley01",15,15,100})]));
}


