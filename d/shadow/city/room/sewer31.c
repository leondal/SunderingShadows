//Titania 10/21/2019
//Shadow Sewers, Room 31

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
	  "north" : ROOMS"sewer9",
	  "south" : ROOMS"sewer32",
   ]));
}
