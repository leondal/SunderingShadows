//path12.c
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
to the ground or be blown away.  To the northwest is a small stone house, 
behind which you can see a miniscule clearing.  The footpath continues 
northeast and south of here.
CIRCE
    );

   set_exits(([
      "northwest" : TROOMS"vil5",
      "northeast" : TROOMS"path11",
      "south" : TROOMS"path13"
      ]));
   set_door("pine door",TROOMS"vil5","northwest",0);
}
