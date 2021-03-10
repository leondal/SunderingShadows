//Titania 10/21/2019
//Shadow Sewers, Room 9

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"sewer31",
      "north" : ROOMS"sewer8",
	  "east" : ROOMS"sewer10",
   ]));
}
