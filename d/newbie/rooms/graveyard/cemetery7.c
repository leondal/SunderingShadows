#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "south":GRAVEYARD"cemetery8",
     "west":GRAVEYARD"cemetery6",
     "northwest":GRAVEYARD"cemetery3",
   ]));
}
