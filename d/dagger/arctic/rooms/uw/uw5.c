#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : UW"uw9",
      "west"        : UW"uw4",
           ]));

}