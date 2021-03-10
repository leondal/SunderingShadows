#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw12",
      "east"        : UW"uw17",
      "south"       : UW"uw19",
      "west"        : UW"uw15",
      "down"        : UW"uwb8",
           ]));

}