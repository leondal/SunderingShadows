//path15.c
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
to the ground or be blown away.  Eastward, the path continues toward 
a larger clearing in the valley, while northwest are a few more 
buildings.  A rather large building stands northeast of here, 
but there does not seem to be an entrance from this side.
CIRCE
    );

   set_exits(([
      "east" : TROOMS"path5",
      "northwest" : TROOMS"path13"
      ]));
}
