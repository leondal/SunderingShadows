#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "west"        : CAVE"cave40",
      "southeast"   : CAVE"cave31",
           ]));
}