#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave42",
      //"east"        : ROOMS"/sp5",
      "south"       : CAVE"cave28",
           ]));
}