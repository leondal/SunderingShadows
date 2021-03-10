//Octothorpe (1/12/12)
//Shadow, Melistel Avenue A

#include <std.h>
#include "../defs.h"

inherit INH+"melistel";

void create(){
   ::create();
   set_long(::query_long()+"To the west an open door leads into a "+
      "%^ORANGE%^general store%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"plaza",
      "south" : ROOMS"melistelb",
      "west" : ROOMS"gs_store",
   ]));
}
