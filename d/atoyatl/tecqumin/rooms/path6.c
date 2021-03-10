#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "north" : ROOMS + "path5", "south": ROOMS + "path7"]));
}

