//path4.c
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
difficult.  A building is just northwest of here, but there seems to be no 
entrance on this side.
CIRCE
    );

   set_exits(([
      "south" : TROOMS"path3",
      "west" : TROOMS"path5",
      "north" : TROOMS"path6",
      "east" : TROOMS"path7"
      ]));
}
