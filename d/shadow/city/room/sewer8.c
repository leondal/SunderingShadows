//Titania 10/21/2019
//Shadow Sewers, Room 8

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"sewer9",
      "west" : ROOMS"sewer7",
	  "north" : ROOMS"sewer17",
   ]));
}
