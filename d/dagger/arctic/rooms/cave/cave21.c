#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : CAVE"cave20",
      "south"       : CAVE"cave7",
      "northwest"   : CAVE"cave22",
           ]));
}