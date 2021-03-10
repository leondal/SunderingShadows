#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;
void create()
  {
  ::create();
  set_exits(([
  "east":TCITY+"c87",
  "west":TCITY+"c85",
  ]));
}
void reset(){
  ::reset();
  if(query_night()) return;
  if(!present("pirate crewman",TO)) {
     new(MON+"piratec.c")->move(TO);
  }
}
