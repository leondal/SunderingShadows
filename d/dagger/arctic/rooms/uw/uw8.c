#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw4",
      "east"        : UW"uw9",
      "south"       : UW"uw12",
      "west"        : UW"uw7",
      "down"        : UW"uwb2",
           ]));

}