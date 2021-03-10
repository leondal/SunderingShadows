//Titania 10/21/2019
//Shadow Sewers, Room 18

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"sewer22",
	  "east" : ROOMS"sewer19",
	  "south" : ROOMS"sewer17",
   ]));
}
