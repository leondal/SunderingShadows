#include <std.h>
#include "../vale.h"
inherit HUT_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"c12",
   ]));
   set_door("door",ROOMS+"c12","east",0);
}

void reset()
{
   ::reset();
   if(!present("druid")) {
      new(MONS+"clone_druid")->move(TO);
   }
}
