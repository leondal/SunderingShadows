//Titania 10/21/2019
//Shadow Sewers, Room 36

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
	  "north" : ROOMS"sewer35",
	  "south" : ROOMS"sewer37",
	  "west" : ROOMS"sewer42",
   ]));
}
