//
//cave7.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_long(
@CIRCE
%^YELLOW%^A Sloping Cavern
%^RESET%^%^ORANGE%^This cavern seems to slope steeply as you continue 
through Echoes Mountains.  Northward, the passage climbs up as the 
walls become more finished.  Around the bend to the southeast, the walls 
are rougher and the floor seems to slope downward.
CIRCE
    );

    set_exits(([
      "southeast" : ROOMS"cave6",
      "north" : ROOMS"cave8"
        ]));

}
