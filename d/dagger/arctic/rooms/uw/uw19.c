#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw16",
      "east"        : UW"uw20",
      "northwest"   : UW"uw15",
           ]));

}