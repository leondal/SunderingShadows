//Titania 10/21/2019
//Shadow Sewers, Room 21

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"sewer20",
	  "south" : ROOMS"sewer14",
   ]));
}
