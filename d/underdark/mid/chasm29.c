#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  A little to the "
"north, the outline of a %^WHITE%^bridge %^BLUE%^comes into focus, spanning out across the chasm, while this short ledge "
"ends here, at a signpost.  There are a few markings and notches upon the wall here.%^RESET%^\n");
   add_item(({"bridge","span"}),"%^BLUE%^A short distance to the north, you can just make out the outline of a "
"%^WHITE%^stone bridge %^BLUE%^that spans across the great chasm, disappearing into %^BOLD%^%^BLACK%^darkness "
"%^RESET%^%^BLUE%^toward the other side.%^RESET%^");
   add_item(({"wall","walls","notches","markings"}),"%^BLUE%^There are a few markings upon the wall here, suggesting "
"someone has climbed down from this point before.  Far below you down the side of the cavern, you can see a small opening "
"to a tunnel.%^RESET%^");
   set_exits(([
     "northwest":MID"chasm28",
   ]));
   set_climb_exits(([
     "descend":({"/d/underdark/lower/dragon/tunnel6",35,roll_dice(4,10),100}),
   ]));
   set_pre_exit_functions(({"northwest"}),({"GoThroughDoor"}));
}

void reset() {
   ::reset();
   if(!present("sign",TO)) new("/d/common/obj/areas/dragonsign")->move(TO);
}
