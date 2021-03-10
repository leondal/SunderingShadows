#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uwb1",
      "east"        : UW"uwb5",
      "south"       : UW"uwb7",
      "up"          : UW"uw11",
           ]));

}