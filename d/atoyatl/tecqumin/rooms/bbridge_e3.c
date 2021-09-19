#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit TECBASE + "ropebridge_base.c";


void create() {
  ::create();
  set_exits(([
      "up" : JUNG_ROOM + "bbridge_e2",
      "up" : JUNG_ROOM + "bbridge_e4",
      "east" : JUNG_ROOM + "bbridge_e2",
      "west" : JUNG_ROOM + "ropebridge5"
   ]));
  set_invis_exits(({"east", "west"}));
}


void init(){
  ::init();
}

