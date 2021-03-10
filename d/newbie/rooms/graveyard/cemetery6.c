#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "west":GRAVEYARD"cemetery5",
     "north":GRAVEYARD"cemetery3",
     "east":GRAVEYARD"cemetery7",
     "southeast":GRAVEYARD"cemetery8",
   ]));
}
