//m3

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FRESH_BLAZE);
   set_property("light",2);
   set_short("%^GREEN%^A dense forest%^RESET%^");
   set_long(
@OLI
   %^GREEN%^A dense forest%^RESET%^
%^BOLD%^%^GREEN%^Fallen %^RESET%^%^ORANGE%^logs %^BOLD%^%^GREEN%^block your path. Low hanging branches threaten
your head. %^RESET%^%^GREEN%^Vines %^BOLD%^hang from the trees. The world rustles
about you. Thick %^RESET%^%^GREEN%^green moss %^BOLD%^clings to the %^RESET%^%^ORANGE%^branches %^BOLD%^%^GREEN%^and
%^ORANGE%^trunks%^BOLD%^%^GREEN%^. The soft %^RESET%^%^GREEN%^mossy floor %^BOLD%^sucks at your feet. You feel
trapped here, unable to move.%^RESET%^
OLI
   );
   set_items(([
      "ground":"Soft and giving, this ground is thickly layered in small plants and various mosses. You notice that to the southeast the wall of the jungle is fuzzy as it meets the ground, almost not real.",
      "vines":"These vines dangle from the trees all around you. These look like your means of transportation.",
      "branches":"Up in the trees it looks as if a whole other world exists up in the trees. Someone might be waiting somewhere up there.",
      "moss":"You've heard that some moss hurts you but this seems to be harmless.",

   ]));

   set_exits(([
//      "northeast":MONASTERY+"m31",
      "southeast":MONASTERY+"hall5",
//      "southwest":MONASTERY+"m30",
      "northwest":MONASTERY+"m30"
   ]));

   set_pre_exit_functions(({"southwest","southeast","northeast","northwest"}),({"swing","swing","swing","swing"}));
   set_invis_exits(({"southeast"}));
   set_smell("default","Wet nature is the best way to describe what you smell.");
   set_listen("default","The trees rustle and the ground sucks on your feet.");
}


int swing(){
   tell_room(TO,"%^GREEN%^"+TPQCN+" grabs a vine and swings "+query_verb()+".",TP);
   tell_object(TP,"%^GREEN%^You grab a vine and swing "+query_verb()+".");
   return 1;
}
