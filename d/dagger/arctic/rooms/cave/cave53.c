#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : LAIR"giants1",
      "east"        : CAVE"cave54",
      "west"        : CAVE"cave52",
           ]));
}