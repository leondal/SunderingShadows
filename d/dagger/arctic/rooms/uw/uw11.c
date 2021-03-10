#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw7",
      "east"        : UW"uw12",
      "south"       : UW"uw15",
      "west"        : UW"uw10",
      "down"        : UW"uwb4",
           ]));

}