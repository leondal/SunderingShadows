#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : CAVE"cave30",
      "south"       : CAVE"cave27",
      "northwest"   : CAVE"cave41",
           ]));
}