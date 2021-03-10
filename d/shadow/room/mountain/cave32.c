//cave32.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
      ""+TO->query_long()+"The tunnel turns here, leading north and "+
      "west.  To the north, it seems to end in a large cavern.\n"
    );
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_exits(([
        "west" : ROOMS"cave31",
        "north" : ROOMS"cave33"
   	]));
}
void reset() {
  ::reset();
  if(!present("mountain giant") && !random(3)) {
    new(MOBS"giant")->move(TO);
  }
}

int go_north() {
   if(TP->query_invis()) return 1;
  if(present("mountain giant")) {
      write("%^MAGENTA%^The giant says:%^RESET%^ The masters do not want to be disturbed.");
    return 0;
  }
  return 1;
}
