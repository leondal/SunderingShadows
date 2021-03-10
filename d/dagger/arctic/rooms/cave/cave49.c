#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : CAVE"cave37",
      "east"        : CAVE"cave50",
      "southwest"   : CAVE"cave36",
           ]));
}