#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  set_monsters(({MOB +"tabaxi_explorer"}), ({1})); 
  set_repop(100);
}
