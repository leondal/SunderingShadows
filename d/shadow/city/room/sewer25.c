//Titania 10/21/2019
//Shadow Sewers, Room 25

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
	  "east" : ROOMS"sewer26",
	  "west" : ROOMS"sewer24",
   ]));
}
