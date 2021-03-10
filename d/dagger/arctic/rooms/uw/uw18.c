#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw14",
      "west"        : UW"uw17",
      "southwest"   : UW"uw20",
           ]));

}