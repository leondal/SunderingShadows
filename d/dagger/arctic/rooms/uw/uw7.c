#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw3",
      "east"        : UW"uw8",
      "south"       : UW"uw11",
      "west"        : UW"uw6",
      "down"        : UW"uwb1",
           ]));

}