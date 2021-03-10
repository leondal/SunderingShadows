//cave2.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_long(
@CIRCE
%^YELLOW%^A Sloping Cavern
%^RESET%^%^ORANGE%^This cavern seems to slope steeply as you continue 
through Echoes Mountains.  To the south, roughly-hewn stone steps lead 
back into the deeper parts of the mountain, while to the northeast the 
journey continues upwards.
CIRCE
    );
   set_items(([
      "steps" : "The steep slope of the cavern floor has been made "+
      "easier by roughly hewn steps leading downwards to the south.",
      ({"cavern","walls","wall"}) : "The dark walls of this cavern seem to be "+
      "hewn rather than naturally carved as the rest of Echoes Mountains.",
      ({"floor","ceiling","stone"}) : "The ceiling seems to be very roughly hewn "+
      "while the dark stone floor has been worn smooth."
      ]));

    set_exits(([
      "down" : ROOMS"cave1",
      "northeast" : ROOMS"cave3"
        ]));

}
