#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw8",
      "east"        : UW"uw13",
      "south"       : UW"uw16",
      "west"        : UW"uw11",
      "down"        : UW"uwb5",
           ]));

}