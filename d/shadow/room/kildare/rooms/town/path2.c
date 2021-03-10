//path2.c
#include "../../kildare.h"

inherit TPATH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, a well-worn footpath 
runs through this tiny valley.  Rising up in front of you are small stone 
houses, made sturdy to resist the wind that has made the bushes cling 
to the ground or be blown away.  The path leads southwest toward an 
opening in the mountainside and northeast into the small town.
CIRCE
    );

    set_exits(([
        "southwest" : TROOMS"path1",
      "northeast" : TROOMS"path3"
        ]));

}
