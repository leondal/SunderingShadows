//Octothorpe (1/22/12)
//Shadow, Dolanco Street 3

#include <std.h>
#include "../defs.h"
inherit INH+"dolanco";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"dolanco4",
      "west" : ROOMS"dolanco2",
      "south" : ROOMS"dock3"
   ]));
}