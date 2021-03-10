#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : UW"uwb6",
      "west"        : UW"uwb2",
      "southwest"   : UW"uwb5",
      "up"          : UW"uw9",
           ]));

}