#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave37",
      "south"       : CAVE"cave23",
      "west"        : CAVE"cave35",
      "northeast"   : CAVE"cave38",
           ]));
}