#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uwb4",
      "east"        : UW"uwb8",
      "northeast"   : UW"uwb5",
      "up"          : UW"uw15",
           ]));

}