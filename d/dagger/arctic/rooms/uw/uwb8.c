#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uwb5",
      "east"        : UW"uwb9",
      "west"        : UW"uwb7",
      "up"          : UW"uw16",
           ]));

}