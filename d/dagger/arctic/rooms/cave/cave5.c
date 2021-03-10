#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "west"        : CAVE"cave6",
      "southeast"   : CAVE"cave3",
           ]));
}