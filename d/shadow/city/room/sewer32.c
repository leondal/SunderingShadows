//Titania 10/21/2019
//Shadow Sewers, Room 32

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
	  "north" : ROOMS"sewer31",
	  "west" : ROOMS"sewer33",
	  "south" : ROOMS"sewer35",
   ]));
}
