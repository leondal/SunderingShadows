#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "north":GRAVEYARD"cemetery7",
     "northwest":GRAVEYARD"cemetery6",
     "west":GRAVEYARD"tomb1",
   ]));
}
