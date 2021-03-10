//path6.c
#include "../../kildare.h"

inherit TPATH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, this well-worn footpath 
runs through this tiny valley.  Rising up around you are small stone 
houses, made sturdy to resist the wind that has made the bushes cling 
to the ground or be blown away.  Just to the west is one of those 
buildings, but there does not seem to be an entrance on this side.  
The path continues to the northwest and leads south into the center 
of the village.
CIRCE
    );

   set_exits(([
      "northwest" : TROOMS"path10",
      "south" : TROOMS"path4"
      ]));
}
