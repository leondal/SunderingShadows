#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave19",
      "southeast"   : CAVE"cave4",
           ]));
}