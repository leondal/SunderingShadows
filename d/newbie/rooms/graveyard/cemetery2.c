#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "west":GRAVEYARD"cemetery1",
     "east":GRAVEYARD"cemetery3",
     "south":GRAVEYARD"cemetery5",
   ]));
}
