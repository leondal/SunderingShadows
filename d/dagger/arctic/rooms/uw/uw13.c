#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw9",
      "east"        : UW"uw14",
      "south"       : UW"uw17",
      "west"        : UW"uw12",
      "down"        : UW"uwb6",
           ]));

}