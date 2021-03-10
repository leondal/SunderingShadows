#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "north":GRAVEYARD"cemetery1",
     "east":GRAVEYARD"cemetery5",
   ]));
}
