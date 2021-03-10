//path10.c
#include "../../kildare.h"

inherit TPATH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, this well-worn footpath 
runs through this tiny valley.  To the northwest, the path continues to an 
impressive stone building while a less-travelled pathway leads higher up 
the mountainside to the northeast.  The footpath you are on leads to a 
smaller building to the south before turning southeast.
CIRCE
    );
   
   set_exits(([
      "northwest" : TROOMS"path11",
      "southeast" : TROOMS"path6",
      "south" : TROOMS"healer",
      "northeast" : ROOMS"ptrail1"
      ]));
}
