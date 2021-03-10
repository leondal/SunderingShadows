#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw13",
      "east"        : UW"uw18",
      "south"       : UW"uw20",
      "west"        : UW"uw16",
      "down"        : UW"uwb9",
           ]));

}