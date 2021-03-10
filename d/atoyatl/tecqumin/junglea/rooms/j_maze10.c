#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {

  set_monsters(({MOB +"dire_warthog"}), ({random(2) + 1})); 
  set_repop(100);
  ::create();
}
