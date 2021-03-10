#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave36",
      "east"        : CAVE"cave34",
      "south"       : CAVE"cave22",
      //"west"        : ROOMS"/sp2",
           ]));
}