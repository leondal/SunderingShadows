//Octothorpe (1/5/12)
//Shadow, Shadow Way B

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_long(::query_long()+"To the north an open door leads into the "+
      "%^RED%^weaponsmith%^RESET%^. %^GREEN%^Dolanco Road %^RESET%^leads to the south.\n");
   set_exits(([
      "north" : ROOMS"weapon",
      "west" : ROOMS"shadwayab",
      "east" : ROOMS"shadwaybc",
	  "south" : ROOMS"dolanco4",
   ]));
}