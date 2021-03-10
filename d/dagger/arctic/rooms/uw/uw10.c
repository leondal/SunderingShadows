#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw6",
      "east"        : UW"uw11",
      "southeast"   : UW"uw15",
           ]));

}