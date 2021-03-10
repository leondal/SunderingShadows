#include <std.h>
#include "./juran.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BLUE%^A narrow tunnel%^RESET%^\n"
"%^BOLD%^%^BLACK%^This narrow corridor is shaped entirely of %^RESET%^%^WHITE%^dull stone%^BOLD%^%^BLACK%^, "
"but only roughly hewn, as though it were not a particularly important passageway.  Small piles of rubble and "
"dust have collected at either side of the corridor, probably shifted by the passing of many feet.  The tunnel "
"itself is left in pure darkness, with no lights to show the way in either direction.%^RESET%^\n");

   set_exits(([
     "southeast":ROOMS"tunnel2",
     "north":ROOMS"tunnel4",
   ]));
}
