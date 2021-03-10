#include <std.h>
#include "../tharis.h"
inherit STORAGE"rich";

void create(){
   ::create();
   set_long(::query_long()+" Just west of here lie the gates out of the city.%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"wgate1",
      "east" : ROOMS"west4",
   ]));
}