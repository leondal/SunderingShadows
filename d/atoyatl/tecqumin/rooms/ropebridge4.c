#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit TECBASE + "ropebridge_base.c";


void create() {
  ::create();
  set_exits(([
      "east" : JUNG_ROOM + "ropebrige3",
      "west" : JUNG_ROOM + "ropebrige5"
   ]));
}


void init(){
  ::init();
}

