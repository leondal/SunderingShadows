#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "west":GRAVEYARD"cemetery4",
     "east":GRAVEYARD"cemetery6",
     "north":GRAVEYARD"cemetery2",
   ]));
}
