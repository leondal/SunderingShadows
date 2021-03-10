//Octothorpe (12/15/16)
//Shadow, Dock 2

#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create()
{
   ::create();
   set_exits(([
      "north" : ROOMS"dock1",
      //"south" : ROOMS"", River ferry 
   ]));
}