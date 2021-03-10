#include <std.h>
#include "../tharis.h"
inherit STORAGE"trade";

void create(){
   ::create();
   set_long(::query_long()+" A small, well-kept store lies east of here, overshadowed by "
"the far brighter shop to the west, which is appointed with large glass windows.%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"bard",
      "east" : ROOMS"tharis_general",
      "south" : ROOMS"north3",
      "north" : ROOMS"north1",
   ]));
}