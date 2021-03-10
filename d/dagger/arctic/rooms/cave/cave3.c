#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave4",
      "south"       : CAVE"cave2",
      "northwest"   : CAVE"cave5",
           ]));
}