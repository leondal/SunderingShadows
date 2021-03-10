//Titania 10/21/2019
//Shadow Sewers, Room 24

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
	  "east" : ROOMS"sewer25",
	  "west" : ROOMS"sewer23",
   ]));
}
