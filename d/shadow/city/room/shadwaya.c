//Octothorpe (1/5/12)
//Shadow, Shadow Way A

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_long(::query_long()+"To the north an open door leads into the "+
      "%^RED%^armorsmith%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"armor",
      "west" : ROOMS"plaza",
      "east" : ROOMS"shadwayab",
   ]));
}