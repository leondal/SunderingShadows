#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave32",
      "southwest"   : CAVE"cave17",
           ]));
}