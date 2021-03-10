//Titania 10/21/2019
//Shadow Sewers, Room 33

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_exits(([
	  "east" : ROOMS"sewer32",
	  "west" : ROOMS"sewer34",
   ]));
}
