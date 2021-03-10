#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : UW"uwb3",
      "west"        : UW"uwb1",
      "south"       : UW"uwb5",
      "up"          : UW"uw8",
           ]));

}