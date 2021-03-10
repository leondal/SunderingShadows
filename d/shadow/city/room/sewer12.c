//Titania 10/21/2019
//Shadow Sewers, Room 12

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"sewer11",
      "north" : ROOMS"sewer13",
   ]));
}
