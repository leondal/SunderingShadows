//path3.c
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
to the ground or be blown away.  Just north of here is an opening in the 
valley, and from there are several pathways leading throughout the town.  
To the southwest, a path leads back into the mountainside.
CIRCE
    );

   set_exits(([
      "southwest" : TROOMS"path2",
      "north" : TROOMS"path4"
      ]));
      new(OBJ"sign")->move(TO);
}
