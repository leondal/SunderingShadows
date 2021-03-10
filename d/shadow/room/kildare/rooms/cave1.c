//cave1.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_long(
@CIRCE
%^YELLOW%^A Sloping Cavern
%^RESET%^%^ORANGE%^This cavern seems to slope upwards as you continue 
through Echoes Mountains.  Just ahead, roughly hewn steps have been 
carved from the floor of the cavern, making the climb upwards a little 
easier.
CIRCE
    );
   set_items(([
      "steps" : "The steep slope of the cavern floor has been made "+
      "easier by roughly hewn steps leading upwards.",
      ({"cavern","walls","wall"}) : "The dark walls of this cavern seem to be "+
      "hewn rather than naturally carved as the rest of Echoes Mountains.",
      ({"floor","ceiling","stone"}) : "The ceiling seems to be very roughly hewn "+
      "while the dark stone floor has been worn smooth."
      ]));

    set_exits(([
      "south" : "/d/shadow/room/mountain/cave19",
      "up" : ROOMS"cave2"
        ]));

}
