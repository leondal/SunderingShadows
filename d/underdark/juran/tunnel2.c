#include <std.h>
#include "./juran.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BLUE%^A narrow tunnel%^RESET%^\n"
"%^BOLD%^%^BLACK%^This narrow corridor is shaped entirely of %^RESET%^%^WHITE%^dull stone%^BOLD%^%^BLACK%^, "
"but only roughly hewn, as though it were not a particularly important passageway.  Small piles of rubble and "
"dust have collected at either side of the corridor, probably shifted by the passing of many feet.  The tunnel "
"itself is left mostly in darkness, with no lights to show the way, although you can just see a %^RESET%^"
"%^WHITE%^faint glow %^BOLD%^%^BLACK%^growing at the eastern end of the corridor.%^RESET%^\n");

   set_exits(([
     "east":ROOMS"tunnel1",
     "northwest":ROOMS"tunnel3",
   ]));
}
