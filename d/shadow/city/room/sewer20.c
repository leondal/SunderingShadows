//Titania 10/21/2019
//Shadow Sewers, Room 20

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"sewer19",
	  "east" : ROOMS"sewer21",
   ]));
}
