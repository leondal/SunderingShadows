//path9.c
#include "../../kildare.h"

inherit PATHEND;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^This short pathway leads from the center of the village 
and climbs a little ways up the mountainside before ending here.  The 
villagers have taken advantage of a relatively flat section of land 
to build two stone buildings here.  There seem to be no windows, but 
each one has a well-built wooden door shut against the cold of the 
mountain air.
CIRCE
    );

   set_exits(([
      "east" : TROOMS"vil3",
      "north" : TROOMS"vil4",
      "southwest" : TROOMS"path7"
      ]));
   set_door("cypress door",TROOMS"vil3","east",0);
   set_door("pine door",TROOMS"vil4","north",0);
   set_door_description("cypress door", "This is a thick cypress door crafted from smooth planks bound in iron.");
   set_door_description("pine door", "This is a thick pine door crafted from knotty pine planks bound in iron.");
}
