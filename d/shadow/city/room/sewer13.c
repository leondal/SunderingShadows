//Titania 10/21/2019
//Shadow Sewers, Room 13

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"sewer12",
      "north" : ROOMS"sewer14",
   ]));
}
