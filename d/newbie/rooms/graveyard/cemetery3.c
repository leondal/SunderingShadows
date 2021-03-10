#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "west":GRAVEYARD"cemetery2",
     "south":GRAVEYARD"cemetery6",
     "southeast":GRAVEYARD"cemetery7",
   ]));
}
