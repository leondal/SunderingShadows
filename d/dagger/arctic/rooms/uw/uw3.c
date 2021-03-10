#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw2",
      "east"        : UW"uw4",
      "south"       : UW"uw7",
      "southwest"   : UW"uw6",
           ]));

}