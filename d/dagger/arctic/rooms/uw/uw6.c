#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : UW"uw7",
      "south"       : UW"uw10",
      "northeast"   : UW"uw3",
           ]));

}