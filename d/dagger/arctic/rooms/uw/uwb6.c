#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uwb3",
      "west"        : UW"uwb5",
      "south"       : UW"uwb9",
      "up"          : UW"uw13",
           ]));

}