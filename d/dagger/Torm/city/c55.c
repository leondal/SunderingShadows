#include <std.h>
#include "../tormdefs.h"
inherit MARKET;
void create()
  {
  ::create();
   set_long(TO->query_long()+" There is a large fountain to the east.");
  set_exits(([
  "north":TCITY+"c44",
  "east":TCITY+"c56",
  "west":TCITY+"c54",
  "south":TCITY+"c63",
  ]));
}

void reset()
{
   ::reset();
   if(query_night() == 1) return;
   else if(!present("teil")) {
      new(MON+"jeweler")->move(TO);
   }
}
