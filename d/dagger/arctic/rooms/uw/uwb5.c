#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uwb2",
      "east"        : UW"uwb6",
      "south"       : UW"uwb8",
      "west"        : UW"uwb4",
      "northeast"   : UW"uwb3",
      "southeast"   : UW"uwb9",
      "southwest"   : UW"uwb7",
      "northwest"   : UW"uwb1",
      "up"          : UW"uw12",
      "down"        : UW"bottom",
           ]));

}