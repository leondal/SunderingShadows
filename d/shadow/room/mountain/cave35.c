//cave35.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
      ""+TO->query_long()+"The cavern turns here, with a tunnel "+
      "going to the west while the other continues north.\n"
    );
 
    set_exits(([
        "north" : ROOMS"cave36",
        "west" : ROOMS"cave34"
   	]));
}
/*
void reset() {
  ::reset();
  if(!present("deep ogre")) {
    new(MOBS"deep")->move(TO);
  }
}

int go_north() {
   if(TP->query_invis()) return 1;
  if(present("deep ogre")) {
      write("%^MAGENTA%^The Deep ogre grunts:%^RESET%^ You won't pass.  Master say so.");
    return 0;
  }
  return 1;
}
*/