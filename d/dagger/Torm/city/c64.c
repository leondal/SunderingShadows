#include <std.h>
#include "../tormdefs.h"
inherit MARKET;
void create()
  {
  ::create();
   set_long(TO->query_long()+" There is a large fountain to the north.");
  set_exits(([
  "north":TCITY+"c56",
  "east":TCITY+"c65",
  "south":TCITY+"c75",
  "west":TCITY+"c63",
  ]));
}

void reset() {
   ::reset();
   if(query_night() == 1) return;
   else if(!present("kedathia")) {
      new(MON+"kedathia")->move(TO);
   }
}
