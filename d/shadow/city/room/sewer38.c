//Titania 10/21/2019
//Shadow Sewers, Room 38

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
    set_long(query_long()[0..(sizeof(query_long()) - 2)] + " %^ORANGE%^A rough hole, dug through the stones, leads down here.\n");
   set_exits(([
	  "north" : ROOMS"sewer37",
          "down":"/d/shadow/ratpaths/rooms/rp_p021_p000",
   ]));
}
