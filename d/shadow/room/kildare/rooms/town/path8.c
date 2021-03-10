//path8.c
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
each one has a door shut against the cold of the mountain air.  
The door to the east is in perfect condition while the southern door 
seems to have been beaten down at one point.  Claw marks can be 
seen along the doorframe there.
CIRCE
    );

   set_exits(([
      "east" : TROOMS"vil1",
      "south" : TROOMS"vil2",
      "southeast" : ROADS"eroad01",
      "northwest" : TROOMS"path7"
      ]));
   set_door("wooden door",TROOMS"vil1","east",0);
   set_door("battered door",TROOMS"vil2","south",0);
}
