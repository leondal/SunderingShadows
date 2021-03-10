//cave3.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_long(
@CIRCE
%^YELLOW%^A Sloping Cavern
%^RESET%^%^ORANGE%^This cavern seems to slope steeply as you continue 
through Echoes Mountains.  The cave narrows here as it turns, then opens 
out again.  A large cavern is just to the north, while a passageway 
leading downwards is to the southwest.
CIRCE
    );

    set_exits(([
      "southwest" : ROOMS"cave2",
      "north" : ROOMS"cave4"
        ]));

}
