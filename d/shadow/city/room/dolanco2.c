//Octothorpe (1/22/12)
//Shadow, Dolanco Street 2

#include <std.h>
#include "../defs.h"
inherit INH+"dolanco";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"dolanco1",
      "east" : ROOMS"dolanco3",
      "north" : ROOMS"bestiary",
      "south" : ROOMS"dock1"
   ]));
}
