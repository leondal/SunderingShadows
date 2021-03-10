//cave6.c
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
out again.  Northwest around the bend, the passageway climbs yet higher, 
while the southeastern route seems to lead deeper into the mountain caves.
CIRCE
    );

    set_exits(([
      "southeast" : ROOMS"cave5",
      "northwest" : ROOMS"cave7"
        ]));

}
