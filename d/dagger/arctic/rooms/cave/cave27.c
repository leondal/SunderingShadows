#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave31",
      "southeast"   : CAVE"cave15",
      "southwest"   : CAVE"cave16",
           ]));
}