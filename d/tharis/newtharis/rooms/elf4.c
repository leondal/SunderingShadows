#include <std.h>
#include "../tharis.h"
inherit STORAGE"elf";

void create(){
   ::create();
   set_long(::query_long()+" Just east of here lie the gates out of the city.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"egate1",
      "west" : ROOMS"elf3",
   ]));
}
