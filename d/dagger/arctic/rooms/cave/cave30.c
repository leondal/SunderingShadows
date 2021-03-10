#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      //"north"       : ROOMS"/sp7",
      "west"        : CAVE"cave31",
      //"southeast"   : ROOMS"/sp8",
           ]));
}