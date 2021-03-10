//Octothorpe (12/15/16)
//Shadow, Dock 4

#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create()
{
   ::create();
   set_exits(([
      "north" : ROOMS"dock3",
      //"south" : ROOMS"", Island ferry/player boat dock
   ]));
}