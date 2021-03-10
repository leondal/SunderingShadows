//Titania 10/21/2019
//Shadow Sewers, Room 15

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"sewer16",
      "east" : ROOMS"sewer14",
   ]));
}
