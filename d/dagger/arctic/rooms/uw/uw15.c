#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw11",
      "east"        : UW"uw16",
      "northwest"   : UW"uw10",
      "southeast"   : UW"uw19",
      "down"        : UW"uwb7",
           ]));

}