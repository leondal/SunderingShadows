//Octothorpe (1/5/12)
//Shadow, Shadow Way 2

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_long(::query_long()+
"The %^BOLD%^%^BLACK%^Shadow Bridge %^RESET%^crosses over the %^BOLD%^%^BLUE%^Sarcosta River %^RESET%^to the west. 
A quaint aroma of %^BOLD%^%^BLACK%^coffee%^RESET%^ comes from the south.");
   set_exits(([
      "west" : ROOMS"shadway3",
      "east" : ROOMS"shadway1",
      "south" : ROOMS"coffeeshop"
   ]));
}


