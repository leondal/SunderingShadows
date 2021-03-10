//path5.c
#include "../../kildare.h"

inherit TPATH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Clearing
%^RESET%^%^CYAN%^The footpaths join to form this small clearing in the center 
of the town.  From here, paths run out in several directions, leading to
many of the small stone buildings spread around.  Little grass grows here, 
and the stone of the mountain makes travel even along the paths a little 
difficult.  A building is just north of here, but there seems to be no 
entrance on this side.  The center of the village is just east of here.
CIRCE
    );

   set_exits(([
      "west" : TROOMS"path15",
      "east" : TROOMS"path4"
      ]));
}
