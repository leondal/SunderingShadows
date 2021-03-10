#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "west"        : CAVE"cave23",
      "south"       : CAVE"cave20",
      "southeast"   : CAVE"cave19",
           ]));
}