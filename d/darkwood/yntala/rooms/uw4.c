//uw4
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater";

void create(){
::create();
set_exits(([
"east":INRMS"uw5",
"west":INRMS"uw3",
]));
}
void reset() {
  ::reset();
  if(!present("shalarin")){
      new(TMONDIR+"shalarin2")->move(TO);
  }
}
