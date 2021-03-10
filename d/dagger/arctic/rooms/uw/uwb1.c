#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uwb.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : UW"uwb2",
      "south"       : UW"uwb4",
      "southeast"   : UW"uwb5",
      "up"          : UW"uw7",
           ]));

}