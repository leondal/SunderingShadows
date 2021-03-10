#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : UW"uw5",
      "south"       : UW"uw8",
      "west"        : UW"uw3",
           ]));

}