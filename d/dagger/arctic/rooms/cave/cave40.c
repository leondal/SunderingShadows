#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      //"west"        : ROOMS"/sp11",
      "east"        : CAVE"cave41",
           ]));
}