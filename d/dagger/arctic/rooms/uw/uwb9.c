#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uwb6",
      "west"        : UW"uwb8",
      "northwest"   : UW"uwb5",
      "up"          : UW"uw17",
           ]));

}