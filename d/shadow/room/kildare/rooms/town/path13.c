//path13.c
#include "../../kildare.h"

inherit PATHEND;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, this well-worn footpath 
runs through this tiny valley.  Rising up around you are small stone 
houses, made sturdy to resist the wind that has made the bushes cling 
to the ground or be blown away.  Just to the west is a doorway into one 
of the buildings, while the path continues southwest and north.  You can 
see what seems to be another clearing to the southwest.
CIRCE
    );

   set_exits(([
      "west" : TROOMS"vil6",
      "north" : TROOMS"path12",
      "southwest" : TROOMS"path14",
      "southeast" : TROOMS"path15"
      ]));
   set_door("wooden door",TROOMS"vil6","west",0);
}
