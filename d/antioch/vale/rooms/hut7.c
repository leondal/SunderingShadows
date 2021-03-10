#include <std.h>
#include "../vale.h"
inherit HUT_INH;

void create()
{
   ::create();
   set_exits(([
   "south" : ROOMS+"c41",
   ]));
   set_door("door",ROOMS+"c41","south",0);
}

void reset()
{
   ::reset();
   if(!present("druid")) {
      new(MONS+"clone_druid")->move(TO);
   }
   return;
}
