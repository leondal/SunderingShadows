//path7.c
#include "../../kildare.h"

inherit TPATH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Clearing
%^RESET%^%^CYAN%^The footpaths join to form this small clearing in the center 
of the town.  Little grass grows here, and the stone of the mountain 
makes travel even along the paths a little difficult.  Pathways branch 
off from here to the northeast and southeast, leading to stone buildings 
in both directions.  The center of town is just west of here.
CIRCE
    );

   set_exits(([
      "west" : TROOMS"path4",
      "northeast" : TROOMS"path9",
      "southeast" : TROOMS"path8"
      ]));
}
