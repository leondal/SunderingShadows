#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : CAVE"cave47",
      "southwest"   : CAVE"cave39",
           ]));
}