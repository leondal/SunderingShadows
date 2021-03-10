#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : UW"uw18",
      "west"        : UW"uw13",
      "northwest"   : UW"uw9",
           ]));

}