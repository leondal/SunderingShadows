#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave55",
      "east"        : CAVE"cave44",
      "west"        : CAVE"cave46",
           ]));
}