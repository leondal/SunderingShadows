#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave24",
      "east"        : CAVE"cave19",
      "west"        : CAVE"cave21",
           ]));
}