#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : UW"uw17",
      "west"        : UW"uw19",
      "northeast"   : UW"uw18",
           ]));

}