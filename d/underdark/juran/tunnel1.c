#include <std.h>
#include "./juran.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_property("light",1);
   set_long("%^BLUE%^A narrow tunnel%^RESET%^\n"
"%^BOLD%^%^BLACK%^You have reached the end of this narrow corridor, where it meets a pair of open gates into a "
"vast cavern beyond.  The tunnel itself is shaped entirely of %^RESET%^%^WHITE%^dull stone%^BOLD%^%^BLACK%^, "
"but only roughly hewn, as though it were not a particularly important passageway.  Small piles of rubble and "
"dust have collected at either side of the corridor, probably shifted by the passing of many feet.  The tunnel "
"itself recedes into darkness, away from this moderately-lit area near the gate.%^RESET%^\n");

   add_item(({"gate","gates"}),"%^BOLD%^%^BLACK%^At the end of the corridor is a pair of dark gates, through "
"which filters what little %^RESET%^%^WHITE%^light %^BOLD%^%^BLACK%^there is here.  They have been left open "
"to permit access into the vast cavern beyond.%^RESET%^");
   set_exits(([
     "east":"/d/underdark/daroldralych/rooms/gatewest",
     "west":ROOMS"tunnel2",
   ]));
}
