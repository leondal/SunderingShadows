//Titania 10/21/2019
//Shadow Sewers, Room 4

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"sewer5",
      "west" : ROOMS"sewer1",
   ]));
}
