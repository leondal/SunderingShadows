#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : CAVE"cave18",
      "northeast"   : CAVE"cave33",
      //"northwest"   : ROOMS"/sp13",
           ]));
}