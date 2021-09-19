#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit TECBASE + "ropebridge_base.c";


void create() {
  ::create();
  set_exits(([
      "west" : JUNG_ROOM + "ropebrige0",
      "east" : JUNG_ROOM + "ropebrige2"
   ]));
}


void init(){
  ::init();
}

