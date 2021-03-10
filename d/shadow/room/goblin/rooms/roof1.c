#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/roof2";
 
void create() {
    ::create();
    set_exits(([
        "down": RPATH "tower1",
    ]));
}

void reset() {
   int r;
  
  ::reset();
  
  if(!present("chest")){
    r = random(2);
    if(r==0)
      new("/d/hm_quest/chests/chest8")->move(TO);
    else
      new("/d/hm_quest/chests/chest26")->move(TO);
  }
}
