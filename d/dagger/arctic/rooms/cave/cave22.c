#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave35",
      "southeast"   : CAVE"cave21",
           ]));
}