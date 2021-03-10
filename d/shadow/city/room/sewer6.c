//Titania 10/21/2019
//Shadow Sewers, Room 6

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"sewer7",
      "west" : ROOMS"sewer5",
   ]));
}
