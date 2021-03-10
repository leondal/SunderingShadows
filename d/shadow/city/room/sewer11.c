//Titania 10/21/2019
//Shadow Sewers, Room 11

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"sewer12",
      "west" : ROOMS"sewer10",
	  "south" : ROOMS"sewer39",
   ]));
}
