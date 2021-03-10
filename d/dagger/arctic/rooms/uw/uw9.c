#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw5",
      "south"       : UW"uw13",
      "west"        : UW"uw8",
      "southwest"   : UW"uw14",
      "down"        : UW"uwb3",
           ]));

}