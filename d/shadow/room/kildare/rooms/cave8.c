//cave8.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_long(
@CIRCE
%^YELLOW%^A Sloping Cavern
%^RESET%^%^ORANGE%^This cavern seems to slope steeply as you continue 
through Echoes Mountains.  To the north, roughly-hewn stone steps lead 
higher up, while to the south the passage goes downward.  A slight breeze 
seems to stir the air here.
CIRCE
    );

   set_items(([
      "steps" : "The steep slope of the cavern floor has been made "+
      "easier by roughly hewn steps leading upwards to the north.",
      ({"cavern","wall","walls"}) : "The dark walls of this cavern seem to be "+
      "hewn rather than naturally carved as the rest of Echoes Mountains.",
      ({"floor","ceiling","stone"}) : "The ceiling seems to be very roughly hewn "+
      "while the dark stone floor has been worn smooth."
   ]));

   set_smell("default","The stale smell of the caverns mingles with fresh air.");

    set_exits(([
      "south" : ROOMS"cave7",
      "up" : ROOMS"cave9"
        ]));

}
