#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"comes to an abrupt end here, leading only to the north into darkness.  This area seems fairly recently mined, "
"as there are little piles of rubble about, and a few tools standing against the stone walls.  A small hole "
"has been breached in the wall itself, probably by the mining, leading into what appears to be a fairly large "
"%^BOLD%^%^BLACK%^cavern %^RESET%^%^BLUE%^beyond.%^RESET%^\n\n%^BOLD%^%^MAGENTA%^A sign is here.\n%^RESET%^");
   set_exits(([
     "north":MINES"lower2p",
     "cavern":"/d/underdark/mid/caverno8",
   ]));
   set_items(([
     "sign":"%^RESET%^%^ORANGE%^A sign has been secured to the wall here, affixed to the rocky wall itself with metal "
"pins.  It reads in scrawled text %^RESET%^'Beware ye, beyond this point lies wild underdark.  Pass at yer own risk'"
"%^ORANGE%^.%^RESET%^",
   ]));
}
